package com.adsl.bluetoothlock;

import java.util.Set;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {
	protected static final int DISCOVERY_REQUEST = 0;

	private BluetoothAdapter btAdapter;

	public TextView statusUpdate;
	public Button connect;
	public Button disconnect;
	public ImageView icon;
	public String toastText = "";
	private String lockName = "linvor";
	private BluetoothDevice lockDevice;

	// Create a BroadcastReceiver to receive state changes
	BroadcastReceiver bluetoothState = new BroadcastReceiver() {
		@Override
		public void onReceive(Context context, Intent intent) {
			String prevStateExtra = BluetoothAdapter.EXTRA_PREVIOUS_STATE;
			String stateExtra = BluetoothAdapter.EXTRA_STATE;
			int state = intent.getIntExtra(stateExtra, -1);
			// int previousState = intent.getIntExtra(prevStateExtra, -1);
			switch (state) {
			case (BluetoothAdapter.STATE_TURNING_ON): {
				toastText = "Bluetooth turning on";
				Toast.makeText(MainActivity.this, toastText, Toast.LENGTH_SHORT)
						.show();
				break;
			}
			case (BluetoothAdapter.STATE_ON): {
				toastText = "Bluetooth on";
				Toast.makeText(MainActivity.this, toastText, Toast.LENGTH_SHORT)
						.show();
				setupUI();
				break;
			}
			case (BluetoothAdapter.STATE_TURNING_OFF): {
				toastText = "Bluetooth turning off";
				Toast.makeText(MainActivity.this, toastText, Toast.LENGTH_SHORT)
						.show();
				break;

			}
			case (BluetoothAdapter.STATE_OFF): {
				toastText = "Bluetooth off";
				Toast.makeText(MainActivity.this, toastText, Toast.LENGTH_SHORT)
						.show();
				setupUI();
				break;
			}
			}
		}
	};

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		setupUI();
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.activity_main, menu);
		return true;
	}

	public void setupUI() {
		// get references to activity_main items
		final TextView statusUpdate = (TextView) findViewById(R.id.result);
		final Button connect = (Button) findViewById(R.id.btnConnect);
		final Button disconnect = (Button) findViewById(R.id.btnDisconnect);
		final ImageView icon = (ImageView) findViewById(R.id.blueIcon);

		// set display view
		disconnect.setVisibility(View.GONE);
		icon.setVisibility(View.GONE);

		btAdapter = BluetoothAdapter.getDefaultAdapter();
		if (btAdapter.isEnabled()) {
			String address = btAdapter.getAddress();
			String name = btAdapter.getName();
			String statusText = name + " : " + address;
			statusUpdate.setText(statusText);
			disconnect.setVisibility(View.VISIBLE);
			icon.setVisibility(View.VISIBLE);
			connect.setVisibility(View.GONE);

		} else {
			connect.setVisibility(View.VISIBLE);
			statusUpdate.setText("Bluetooth is not on");
		}

		connect.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) {
				// String actionStateChanged =
				// BluetoothAdapter.ACTION_STATE_CHANGED;
				// String actionRequestEnable =
				// BluetoothAdapter.ACTION_REQUEST_ENABLE;
				// IntentFilter filter = new IntentFilter(actionStateChanged);
				// registerReceiver(bluetoothState, filter);
				// startActivityForResult(new Intent(actionRequestEnable), 0);

				String scanModeChanged = BluetoothAdapter.ACTION_SCAN_MODE_CHANGED;
				String beDiscoverable = BluetoothAdapter.ACTION_REQUEST_DISCOVERABLE;
				IntentFilter filter = new IntentFilter(scanModeChanged);
				registerReceiver(bluetoothState, filter);
				startActivityForResult(new Intent(beDiscoverable),
						DISCOVERY_REQUEST);

			}
		}); // end connect onClickListener

		disconnect.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				btAdapter.disable();
				connect.setVisibility(View.VISIBLE);
				disconnect.setVisibility(View.GONE);
				icon.setVisibility(View.GONE);
				statusUpdate.setText("Bluetooth Off");

			}
		}); // end disconnect onClickListener
	} // end setupUI

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent date) {
		if (requestCode == DISCOVERY_REQUEST) {
			Toast.makeText(MainActivity.this, "Discovery in progress",
					Toast.LENGTH_SHORT).show();
			setupUI();
			findDevices();
		}
	}

	private void findDevices() {

		toastText = "Checking for known paired devices";
		Toast.makeText(MainActivity.this, toastText, Toast.LENGTH_SHORT).show();

		Set<BluetoothDevice> pairedDevices = btAdapter.getBondedDevices();

		if (pairedDevices.size() > 0) {
			for (BluetoothDevice pairedDevice : pairedDevices) {
				toastText = "Found device: " + pairedDevice.getName();
				System.out.println(pairedDevice.getName());
				if (lockName.equals(pairedDevice.getName())) {
					lockDevice = pairedDevice;
					toastText += " = Magic Lock";
					System.out.println("Found the lock, paired");
				}
				Toast.makeText(MainActivity.this, toastText, Toast.LENGTH_SHORT).show();
			}
		}

		if (lockDevice == null) {
			toastText = "Starting discovery for remote devices...";
			Toast.makeText(MainActivity.this, toastText, Toast.LENGTH_SHORT)
					.show();
			// start discovery
			if (btAdapter.startDiscovery()) {
				toastText = "Discovery thread started... Scanning for Devices";
				Toast.makeText(MainActivity.this, toastText, Toast.LENGTH_SHORT)
						.show();
				registerReceiver(discoveryResult, new IntentFilter(
						BluetoothDevice.ACTION_FOUND));
			}
		}
	} // end find devices

	// Create BroadcastReceiver to receive device discovery
	BroadcastReceiver discoveryResult = new BroadcastReceiver() {
		@Override
		public void onReceive(Context context, Intent intent) {
			String remoteDeviceName = intent
					.getStringExtra(BluetoothDevice.EXTRA_NAME);
			BluetoothDevice remoteDevice;
			remoteDevice = intent
					.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);

			if (remoteDeviceName == lockName) {
				lockDevice = remoteDevice;
				System.out.println("Found the lock, unpaired");
			}
			toastText = "Discovered: " + remoteDeviceName;
			Toast.makeText(MainActivity.this, toastText, Toast.LENGTH_SHORT)
					.show();
			// statusUpdate.setText(statusText);
		}
	};
}

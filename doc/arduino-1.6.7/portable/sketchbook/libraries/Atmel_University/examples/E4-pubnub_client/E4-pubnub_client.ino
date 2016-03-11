
/*
  PubNub over WiFi Example using WiFi Shield 101
  This sample client will publish raw (string) PubNub messages from boards like Arduino Uno and Zero with WiFi Shield 101

  See https://www.arduino.cc/en/Reference/WiFi101 for more info

  created Dec 17, 2015
  by Tomomi Imura

  modified Jan 12 / 2016  by Bob Martin, Atmel Corp
*/

#include <SPI.h>

#include <WiFi101.h>
#include <PubNub.h>

static char ssid[] = "?? ssid ??";   			// your network SSID (name)
static char pass[] = "?? password ??";     		// your network password
int status = WL_IDLE_STATUS;                	// the Wifi radio's status

const static char pubkey[] = "?? your pubkey ??";
const static char subkey[] = "?? your subkey ??";
const static char channel[] = "test_channel";


char uart_str[80];

void setup()
{
  Serial.begin(115200);
  while(!Serial) ;

  Serial.println("PubNub Arduino Zero WiFi101 example project V1.0");
  Serial.println("Jan 2016 / Atmel Corp");

  if (WiFi.status() == WL_NO_SHIELD)
  {
    Serial.println("WiFi101 shield not present");

    while (true);
    // attempt to connect using WEP encryption:
  }
  Serial.println("Initializing Wifi...");
  // printMacAddress();

  String fv = WiFi.firmwareVersion();
  Serial.print("firmware version ");
  Serial.println(fv);


  // attempt to connect using WPA2 encryption:
  Serial.println("Connect to network...");
  status = WiFi.begin(ssid, pass);

  // if you're not connected, stop here:
  if ( status != WL_CONNECTED)
  {
    Serial.println("Connect fail");
    while (true);
  }
  else
  {
    Serial.print("connected to SSID: ");
    Serial.println(ssid);

    PubNub.begin(pubkey, subkey);
    Serial.println("PubNub set up");
  }
}


int adc_data[4];

void read_adc_channels(void)
{
	int channel_id;

	Serial.println("Reading ADC channels 0 - 3");

	for(channel_id = 0; channel_id < 4;channel_id++)
  {
    adc_data[channel_id] = analogRead(channel_id);
    sprintf(uart_str,"ch %d : %d\r\n",channel_id,adc_data[channel_id]);
    Serial.println(uart_str);
  }
}

WiFiClient *client;

char msg[40];

void loop()
{
	read_adc_channels();

	sprintf(msg,"{\"ch0\":\"%d\"}",adc_data[0]);
	client = PubNub.publish(channel, msg);

	sprintf(msg,"{\"ch1\":\"%d\"}",adc_data[1]);
	client = PubNub.publish(channel, msg);

	sprintf(msg,"{\"ch2\":\"%d\"}",adc_data[2]);
	client = PubNub.publish(channel, msg);

	sprintf(msg,"{\"ch3\":\"%d\"}",adc_data[3]);
	client = PubNub.publish(channel, msg);

	/*
	sprintf(buf, "{\"device\":\"%s\", \"temperature\":\"%d.%d\", \"light\":\"%d\", \"led\":\"%s\"}",
						PubNubChannel,
						(int)temperature, (int)((int)(temperature * 100) % 100),
						(((4096 - light) * 100) / 4096),
						port_pin_get_output_level(LED0_PIN) ? "0" : "1");

	*/

	// client = PubNub.publish(channel,"\"Hey There\"" );

	if (!client)
  {
		Serial.println("publishing error");
  }
	else
  {
    Serial.println("msg published");
  }

	client->stop();

	delay(1000);
}














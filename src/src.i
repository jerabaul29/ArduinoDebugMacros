int i;
int *pi;
char c;
char *pc;
void setup(){
  delay(1000);
  Serial.begin(9600); delay(100); Serial.println();
  Serial.println(F("D " "Compiled " "Apr 15 2018" " " "00:45:56")); Serial.println(F("D " "Debug on " "Serial"));
  i = 4;
  c = 'b';
  Serial.println(F("D " "Start loop"));;
  Serial.print(F("D " "i" " ")); Serial.println(i);
  Serial.print(F("D " "c" " ")); Serial.println(c);
  Serial.println(F("D " "src.cpp" " l " "24"));
  Serial.println(F("D " "SOME_MACRO" " " "bbbbbbbbbbb Serial"));
}
void loop(){
}

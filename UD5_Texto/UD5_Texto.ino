/**
 * UD_5 Texto
 *
 */

char textoChar[8] = {'a','r','d','u','i','n','o','\0'}; // Array terminado con un carácter nulo
char textoCharSin0[8] = {'a','r','d','u','i','n','o'};
char textoCharDeString[8] = "arduino"; // Array generado por el compilador a partir de un String
char textoCharDeStringSinTamano[] = "arduino";

String textoString = String(15); // Variable del tipo String (Por defecto DEC)
String textoStringHexadecimal = String(15, HEX);
String textoStringBinario = String(15, BIN);
String textoStringDecimales = String(15.3231241, 2); // El segundo parámetro denota el número de decimales
String textoConcatenado = String("Número " + textoString);

String textoTemperatura = "Temperatura: ";

void setup() {

  Serial.begin(9600);
  Serial.println(textoChar);
}

void loop() {


  Serial.println(textoTemperatura + analogRead(0) + "ºC");
}

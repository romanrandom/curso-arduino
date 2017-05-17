/**
  Unidad 6: JSON
  Obtenemos datos de openweathermap.org y los mostramos por pantalla
  En claveAPI debe ir la APIkey obtenida tras darse de alta en la web
*/

String claveAPI = "xxxxxxxxxxxxxxxx";
String query = "q=bilbao&units=metric";

void setup() {
  
  JSONObject respuesta = loadJSONObject("http://api.openweathermap.org/data/2.5/weather?" + query + "&appid=" + claveAPI);
  JSONObject main = respuesta.getJSONObject("main");

  int temperatura = main.getInt("temp");
  
  fill(0);
  textAlign(CENTER);
  textSize(50);
  text(temperatura, width/2, width/2 + 18);
  
  
}
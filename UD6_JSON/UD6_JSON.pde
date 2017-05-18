/**
  Unidad 6: JSON
  Obtenemos datos de openweathermap.org y los mostramos por pantalla
  En claveAPI debe ir la APIkey obtenida tras darse de alta en la web
*/

String claveAPI = "7844f3eec4bfc5c936a0abd504804bfe";
String query = "q=bilbao&units=metric&lang=es";

void setup() {
  
  size(300, 200);
  background(255);
  
  JSONObject respuesta = loadJSONObject("http://api.openweathermap.org/data/2.5/weather?" + query + "&appid=" + claveAPI);
  JSONObject main = respuesta.getJSONObject("main");

  int temperatura = main.getInt("temp");
  
  JSONObject weather = respuesta
    .getJSONArray("weather")
    .getJSONObject(0);
  
  String descripcion = weather.getString("description");
  
  fill(0);
  textAlign(CENTER);
  textSize(70);
  text(temperatura, width / 2, height / 2);
  
  textSize(20);
  text(descripcion, width / 2, height * 2/3);
  
}
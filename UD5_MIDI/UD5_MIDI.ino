/** 
 *  Unidad 5: MIDI
 *  Notas MIDI:
 *  http://www.midimountain.com/midi/midi_note_numbers.html
 */

#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

byte nota;

void setup() {
    
  MIDI.begin();           // Podemos seleccionar el canal o usar 1 por defecto
  Serial.begin(115200);

}

void loop() {
  
  nota = random(60, 96);
  
  MIDI.sendNoteOn(nota, 127, 1);    // Envía una nota (pitch 42, velocity 127, canal 1)
  delay(333);                       
  MIDI.sendNoteOff(nota, 0, 1);     // Para la nota
  delay(333);
  MIDI.sendNoteOn(nota - 12, 100, 1);
  delay(333);
  MIDI.sendNoteOff(nota - 12, 0, 1);
}

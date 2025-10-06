import kivy
from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.progressbar import ProgressBar
from kivy.clock import Clock
import sounddevice as sd
import numpy as np
print(sd.query_devices())

# Configuración de audio
FRECUENCIA = 44100
DURACION = 0.1  # segundos por bloque de audio

class VUMeter(BoxLayout):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self.orientation = "vertical"

        # Barra de progreso (0 a 60 dB)
        self.barra = ProgressBar(max=100)  # en vez de 60
        self.add_widget(self.barra)

        # Llama a "actualizar" cada 100 ms
        Clock.schedule_interval(self.actualizar, 0.1)

    def medir_audio(self):
        # Captura un bloque de audio
        audio = sd.rec(int(DURACION * FRECUENCIA),
                        samplerate=FRECUENCIA,
                        channels=1,
                        dtype='float64',
                        device=24)
        sd.wait()
        # RMS -> dB
        rms = np.sqrt(np.mean(np.square(audio)))
        dB = 20 * np.log10(rms + 1e-6)  # +1e-6 evita log(0)
        return max(0, min(100, abs(dB)))  # convierte a rango 0-100

    def actualizar(self, dt):
        nivel = self.medir_audio()
        print("Nivel medido:", nivel)  # 👈 debug
        self.barra.value = nivel


class VUApp(App):
    def build(self):
        return VUMeter()

if __name__ == "__main__":
    VUApp().run()

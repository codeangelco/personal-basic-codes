import random
import os

class Jugador:
    def __init__(self, nombre : str = "Jugador"):
        self.nombre = nombre
        self.puntaje = dict.fromkeys(("victorias","derrotas","empates"), 0)

class Juego:
    def __init__(self, jugador : Jugador = Jugador()):
        self.jugador = jugador
        self.partidas_jugadas = 0
        self.reglas = {
            "Piedra" : ["Tijera","Lagarto"],
            "Papel" : ["Piedra","Spock"],
            "Tijera" : ["Papel","Lagarto"],
            "Lagarto" : ["Papel","Spock"],
            "Spock" : ["Piedra","Tijera"]
        }


    def resultado(self) -> str:
        return f"\n\tVictorias: {self.jugador.puntaje['victorias']}\n\tDerrotas: {self.jugador.puntaje['derrotas']}\n\tEmpates: {self.jugador.puntaje['empates']}"


    def jugada(self, jugada_p1: str, jugada_p2: str) -> int:
        if jugada_p2 in self.reglas[jugada_p1]:
            return 1
        elif jugada_p1 in self.reglas[jugada_p2]:
            return -1
        else:
            return 0

    def final(self) -> None:
        os.system("cls" if os.name == "nt" else "clear")
        print("\t¡Juego terminado!")
        if self.jugador.puntaje["victorias"] > self.jugador.puntaje["derrotas"]:
            print(f"Felicitaciones {self.jugador.nombre}!\nTu marcador es:", self.resultado())
        else:
            print(f"Mejor suerte la proxima {self.jugador.nombre}!\nTu marcador es:", self.resultado())
    
    
    def menu(self) -> None:
        print("0. Salir")
        lista = list(self.reglas.keys())
        for i,jugada in enumerate(lista,start=1):
            print(f"{i}. {jugada}")
            
            

def main():
    try:
        print("\t¡Pedra, Papel y Tijera! Con... Lagarto? Y Spock??!!")
        nombre = input("Ingresa tu nombre: ")
        juego = Juego(Jugador(nombre))
        
        cantidad_rondas = 0
        while cantidad_rondas != 1 and cantidad_rondas != 2:
            try:
                cantidad_rondas = int(input("\nJugar rondas ilimitadas (1) o cierta cantidad de rondas (2)?: "))
            except:
                print("Solo puedes ingresar valores numericos, entre las opciones 1 y 2.")
                
        if cantidad_rondas == 2:
            while True:
                try:
                    cantidad_rondas = int(input("\nDigite la cantidad de rondas a jugar: "))
                    break
                except:
                    print("Ingresa solo valores numericos.")
                    
            if cantidad_rondas < 1:
                print("Error: Juego no iniciado correctamente")
                return
        else:
            cantidad_rondas = 1000000
        os.system("cls" if os.name == "nt" else "clear")
        for i in range(cantidad_rondas):
            juego.menu()
            while True:
                try:
                    decision = int(input("Ingresa tu opcion: "))
                    break
                except:
                    print("Ingresa solo valores numericos.")
            if decision == 0:
                juego.final()
                break
            maquina = random.randrange(1,6)
            opciones = list(juego.reglas.keys())
            print(f"Bot eligio {opciones[maquina-1]}")
            ds = juego.jugada(opciones[decision-1],opciones[maquina-1])
            if ds == 1:
                juego.jugador.puntaje["victorias"] += 1
            elif ds == 0:
                juego.jugador.puntaje["empates"] += 1
            else:
                juego.jugador.puntaje["derrotas"] += 1
        else:
            juego.final()
    except Exception as ex:
        print("\n¡ERROR!")
        print("Nombre:", type(ex).__name__)
        print("Mensaje:", ex.args[0])
        os.system("pause")
        os.system("cls" if os.name == "nt" else "clear")
        main()


os.system("cls" if os.name == "nt" else "clear")
main()
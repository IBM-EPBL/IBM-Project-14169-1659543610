import time
import winsound

for i in range(0,100):
    temperature = int(input("Enter temperature in Celcius: "))
    humidity = int(input("Enter humidity between 100: "))
    try:
        if(temperature > 40 and humidity > 40):
            winsound.PlaySound('fire.wav', winsound.SND_FILENAME)
            time.sleep(10)
    except:
        print("sound played")
    

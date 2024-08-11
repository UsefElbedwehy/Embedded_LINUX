import webbrowser
import pyautogui
import time

pyautogui.hotkey('win')
time.sleep(1)
pyautogui.typewrite('vs')
time.sleep(1)

try:
    vs_locate = None
    while vs_locate is None:
        vs_locate = pyautogui.locateOnScreen('vscode_image.png',confidence=0.8)

except pyautogui.ImageNotFoundException:
    print("vscode image is not found")

pyautogui.hotkey('enter')

webbrowser.open('https://play.anghami.com/likes')
time.sleep(8)

try:
    anghami_location = None
    while anghami_location is None:
        anghami_location = pyautogui.locateOnScreen('AnghamiImage.png',confidence=0.8)
    if anghami_location is not None:
        pyautogui.moveTo(anghami_location[0]+10,anghami_location[1]+20,duration=0.5)
        time.sleep(0.1)

except pyautogui.ImageNotFoundException:
    print("Anghami image is not found")

time.sleep(1)
pyautogui.click()





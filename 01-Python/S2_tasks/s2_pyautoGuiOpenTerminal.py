import pyautogui
import os
import time

#press windows key
pyautogui.hotkey('win')
time.sleep(2)
#write termi in the search
pyautogui.typewrite('termin')
#delay 1 sec
time.sleep(2)
#locate the icon on the screen

try:
    icon_location = None
    while icon_location is None:
        icon_location = pyautogui.locateOnScreen('terminal_icon.png', confidence=0.8)
        #time.sleep(1)

except pyautogui.ImageNotFoundException:
    print('image is not found...')


pyautogui.hotkey('enter')
time.sleep(2)
pyautogui.typewrite('Hello frients hehe')















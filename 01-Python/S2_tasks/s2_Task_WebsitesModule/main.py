import firelink

status = True

while status == True:
    print("1- Facebook")
    print("2- Whatsapp")
    print("3- Anghami")
    print("4- Chatgpt")
    print("5- Quit")
    user_choice = str(input("Choose a website to open: "))
    if user_choice == '1':
        firelink.firefox(firelink.facebook_link)
    elif user_choice == '2':
        firelink.firefox(firelink.Whatsapp_link)
    elif user_choice == '3':
        firelink.firefox(firelink.Anghami_link)
    elif user_choice == '4':
        firelink.firefox(firelink.ChatGpt_link)
    elif user_choice == '5':
        status = False
    else:
        print("Wronge answer")
        print("try again...")

print("Have a nice day browsing")



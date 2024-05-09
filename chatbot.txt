from nltk.chat.util import Chat, reflections
import webbrowser
from datetime import date, datetime

# Define pairs of patterns and responses
pairs = [
    ['hi|hello', ['Hello!', 'Hi there!', 'Hey!']],
    ['how are you?', ['I am good, thank you!', 'Feeling great!', 'I am doing well, thanks for asking.']],
    ['what is your name?', ['I am a chatbot.', 'You can call me a chatbot.']],
    ['bye', ['Goodbye!', 'See you later!', 'Bye!']],
    ['browser|open browser', ['Opening Browser...']],
    ['date', [f"Today's date is {date.today()}"]],
    ['time', [f"Current time is {datetime.now().time()}"]]
]

# Create a Chat object  
chatbot = Chat(pairs, reflections)

# Start chatting
print("Welcome to the chatbot!")
while True:
    user_input = input("You: ")
    response = chatbot.respond(user_input)
    if(user_input == 'browser' or user_input == 'open browser'):
        webbrowser.open('www.google.com')
    print("Bot:", response)
    if (user_input.lower() == 'exit'):
        break

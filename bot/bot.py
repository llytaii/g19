from asyncore import write
import logging
import requests
import time
import threading
import random

from telegram import Update
from telegram.error import Unauthorized, BadRequest
from telegram.ext import Updater, CommandHandler, MessageHandler, Filters, CallbackContext

# LOGGING 
logging.basicConfig(
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s', level=logging.INFO
)
logger = logging.getLogger(__name__)



# BOT 
with open('token.txt') as f:
    token = f.read().strip()

updater = Updater(token)
dispatcher = updater.dispatcher
bot = updater.bot

def start(update: Update, context: CallbackContext) -> None:
    help(update, context)

def help(update: Update, context: CallbackContext) -> None:
    context.bot.send_message(chat_id=update.effective_chat.id, text="send a picture that will be displayed on my g19 display")

def image_handler(update: Update, context: CallbackContext) -> None:
    file = update.message.photo[-1].get_file()
    file.download("/home/llytaii/g19/wallpaper.jpg")

def main() -> None:
    dispatcher.add_handler(CommandHandler("start", start))
    dispatcher.add_handler(CommandHandler("help", help))
    dispatcher.add_handler(MessageHandler(Filters.photo, image_handler))

    updater.start_polling()
    updater.idle()
   

if __name__ == '__main__':
    main()    
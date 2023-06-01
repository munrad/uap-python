import os
from . import pyuapcpp

regex_file_path = os.path.dirname(os.path.abspath(__file__)) + '/regexes.yaml'

# Инициализация парсера при импорте модуля
pyuapcpp.init_parser(regex_file_path)
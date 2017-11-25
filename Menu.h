#pragma once

enum MainMenu { M_login, M_signup, M_exit };
MainMenu ShowMenu();

enum LoginMenu { L_wordbook, L_memorize, L_quiz, L_exit };
LoginMenu ShowLoginMenu();

enum WordbookMenu { W_all, W_add, W_search, W_exit };
WordbookMenu ShowWordbookMenu();
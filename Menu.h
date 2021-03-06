#include "member.h"


enum MainMenu { M_login, M_signup, M_exit };
MainMenu ShowMenu();

enum LoginMenu { L_wordbook, L_memorize, L_quiz, L_exit };
LoginMenu ShowLoginMenu(Member* member);

enum WordbookMenu { W_add, W_search, W_delete, W_exit };
WordbookMenu ShowWordbookMenu(Member* member);

enum StudyMenu { S_bookmark, S_Meaning, S_Word, S_Together, S_exit};
StudyMenu ShowStudyMenu(Member* member );

enum QuizMenu { Q_bookmarkquiz, Q_meaningquiz, Q_exit };
QuizMenu ShowQuizMenu(Member* member);

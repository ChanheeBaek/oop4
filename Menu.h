#include "member.h"


enum MainMenu { M_login, M_signup, M_exit };
MainMenu ShowMenu();

enum LoginMenu { L_wordbook, L_memorize, L_quiz, L_exit };
LoginMenu ShowLoginMenu(Member* member);

enum WordbookMenu { W_all, W_add, W_search, W_exit };
WordbookMenu ShowWordbookMenu(Member* member);


enum AdminMenu { A_add, A_search, A_delete, A_exit };
AdminMenu ShowAdminMenu(Member* member);

enum StudyMenu { S_bookmark, S_Meaning, S_Word, S_Together, S_exit};
StudyMenu ShowStudyMenu(Member* member );


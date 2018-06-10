#include "Guest.h"
  class GuestMysql:public UserMysql{
  public:
 -    bool existUsername(QString username);
 -    QString getPassword(QString username);
      void modifyPassword(QString password);
 -    std::vector<Guest*> find_guest(QString type, QString feature);
  };
  
  #endif // GUESTMYSQL_H

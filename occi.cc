#include <exception>
#include <stdexcept>
#include <string>

#define OCCI_STD_NAMESPACE std

namespace oracle {
namespace occi {

class Date;
class Clob;
class Timestamp;
class Number;
class Environment;
class SQLException;
class Connection;
class Stream;

#define OCI_LOB_READONLY 1
#define OCI_LOB_READWRITE 2
#define OCI_LOB_WRITEONLY 3
#define OCI_LOB_APPENDONLY 4
#define OCI_LOB_FULLOVERWRITE 5
#define OCI_LOB_FULLREAD 6

#define OCI_DEFAULT 0x00000000
#define OCI_OBJECT 0x00000002
#define OCI_SHARED 0x00000010
#define OCI_NO_UCB 0x00000040
#define OCI_THREADED 0x00000001
#define OCI_NO_MUTEX 0x00000080
#define OCI_EVENTS 0x00000004
#define OCI_USE_LDAP 0x00001000

enum LobOpenMode {
  OCCI_LOB_READONLY = OCI_LOB_READONLY,
  OCCI_LOB_READWRITE = OCI_LOB_READWRITE,
  OCCI_LOB_WRITEONLY = OCI_LOB_WRITEONLY,
  OCCI_LOB_APPENDONLY = OCI_LOB_APPENDONLY,
  OCCI_LOB_FULLOVERWRITE = OCI_LOB_FULLOVERWRITE,
  OCCI_LOB_FULLREAD = OCI_LOB_FULLREAD
};

#define THROW_RUNTIME                                                         \
  throw std::runtime_error("Unsupported call to Oracle library, function: " + \
                           std::string(__PRETTY_FUNCTION__))

class Date {
 public:
  Date();
  Date(const Environment *envp, int year = 1, unsigned int month = 1,
       unsigned int day = 1, unsigned int hour = 0, unsigned int minute = 0,
       unsigned int seconds = 0);
  ~Date();
  void getDate(int &year, unsigned int &month, unsigned int &day,
               unsigned int &hour, unsigned int &min, unsigned int &sec) const;
  OCCI_STD_NAMESPACE::string toText(
      const OCCI_STD_NAMESPACE::string &fmt = "",
      const OCCI_STD_NAMESPACE::string &nlsParam = "") const;
  Date &operator=(const Date &d);
  bool isNull() const;
};  // class Date

Date::Date() { THROW_RUNTIME; };
Date::Date(const Environment *envp, int year, unsigned int month,
           unsigned int day, unsigned int hour, unsigned int minute,
           unsigned int seconds) {
  THROW_RUNTIME;
};
Date::~Date() { THROW_RUNTIME; };
void Date::getDate(int &year, unsigned int &month, unsigned int &day,
                   unsigned int &hour, unsigned int &min,
                   unsigned int &sec) const {
  THROW_RUNTIME;
};
OCCI_STD_NAMESPACE::string Date::toText(
    const OCCI_STD_NAMESPACE::string &fmt,
    const OCCI_STD_NAMESPACE::string &nlsParam) const {
  THROW_RUNTIME;
};
Date &Date::operator=(const Date &d) { THROW_RUNTIME; };
bool Date::isNull() const { THROW_RUNTIME; };

class Clob {
 public:
  Clob(const Connection *connectionp);
  Clob(const Clob &srcClob);
  ~Clob();
  unsigned int length() const;
  void setEmpty();
  void open(LobOpenMode mode = OCCI_LOB_READWRITE);
  void close();
  Stream *getStream(unsigned int offset = 1, unsigned int amount = 0);
  void closeStream(Stream *stream);
};  // class Clob

Clob::Clob(const Connection *connectionp) { THROW_RUNTIME; };
Clob::Clob(const Clob &srcClob) { THROW_RUNTIME; };
Clob::~Clob() { THROW_RUNTIME; };
unsigned int Clob::length() const { THROW_RUNTIME; };
void Clob::setEmpty() { THROW_RUNTIME; };
void Clob::open(LobOpenMode mode) { THROW_RUNTIME; };
void Clob::close() { THROW_RUNTIME; };
Stream *Clob::getStream(unsigned int offset, unsigned int amount) {
  THROW_RUNTIME;
};
void Clob::closeStream(Stream *stream) { THROW_RUNTIME; };

class Timestamp {
 public:
  ~Timestamp();
  
  OCCI_STD_NAMESPACE::string toText(
      const OCCI_STD_NAMESPACE::string &fmt, unsigned int fsprec,
      const OCCI_STD_NAMESPACE::string &nlsParam = "") const;
  void getDate(int&, unsigned int&, unsigned int&) const;
  void getTime(unsigned int&, unsigned int&, unsigned int&, unsigned int&) const;
};  // class Timestamp

Timestamp::~Timestamp() { THROW_RUNTIME; };
OCCI_STD_NAMESPACE::string Timestamp::toText(
    const OCCI_STD_NAMESPACE::string &fmt, unsigned int fsprec,
    const OCCI_STD_NAMESPACE::string &nlsParam) const {
  THROW_RUNTIME;
};
void Timestamp::getTime(unsigned int&, unsigned int&, unsigned int&, unsigned int&) const{THROW_RUNTIME;}
void Timestamp::void getDate(int&, unsigned int&, unsigned int&) const {THROW_RUNTIME;}

class Number {
 public:
  ~Number();
  operator unsigned long() const;
};  // class Number

Number::~Number() { THROW_RUNTIME; };
Number::operator unsigned long() const { THROW_RUNTIME; };

class Environment {
 public:
  enum Mode {
    DEFAULT = OCI_DEFAULT,
    OBJECT = OCI_OBJECT,
    SHARED = OCI_SHARED,
    NO_USERCALLBACKS = OCI_NO_UCB,
    THREADED_MUTEXED = OCI_THREADED,
    THREADED_UNMUTEXED = OCI_THREADED | OCI_NO_MUTEX,
    EVENTS = OCI_EVENTS,
    USE_LDAP = OCI_USE_LDAP
  };

  static Environment *createEnvironment(
      Mode mode = DEFAULT, void *ctxp = 0,
      void *(*malocfp)(void *ctxp, size_t size) = 0,
      void *(*ralocfp)(void *ctxp, void *memptr, size_t newsize) = 0,
      void (*mfreefp)(void *ctxp, void *memptr) = 0);

  static void terminateEnvironment(Environment *env);
};  // class Environment

Environment *Environment::createEnvironment(
    Mode mode, void *ctxp, void *(*malocfp)(void *ctxp, size_t size),
    void *(*ralocfp)(void *ctxp, void *memptr, size_t newsize),
    void (*mfreefp)(void *ctxp, void *memptr)) {
  THROW_RUNTIME;
};

void Environment::terminateEnvironment(Environment *env) { THROW_RUNTIME; };

class SQLException : public OCCI_STD_NAMESPACE::exception {
 public:
  virtual int getErrorCode() const;
  virtual OCCI_STD_NAMESPACE::string getMessage() const;
  SQLException(const SQLException &e);
  virtual ~SQLException() throw();
};  // class SQLException

int SQLException::getErrorCode() const { THROW_RUNTIME; };
OCCI_STD_NAMESPACE::string SQLException::getMessage() const { THROW_RUNTIME; };
SQLException::SQLException(const SQLException &e) { THROW_RUNTIME; };
SQLException::~SQLException() throw() { THROW_RUNTIME; };

class Connection {};

class Stream {};
}
}

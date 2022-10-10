#include<iostream>
#include<unistd.h>

using namespace std;

int main()
{
  pid_t id = fork();
  if (id == 0)
  {
    // child
    while (1)
    {
      cout << "I am child, running!" << endl;
      sleep(2);
    }
  }
  else 
  {
    // parent
    cout << "father do nothing" << endl;
    sleep(50);

  }
//  while (true)
//  {
//    std::cout << "Hello world" << std::endl;
//  }
  //pid_t id = fork();
  //if (id == 0)
  //{
  //  // child
  //  while (true)
  //  {
  //    std::cout << "I am child, pid: " << getpid() << ", ppid:" << getppid() << std::endl;
  //    sleep(1);
  //  }
  //}
  //else if (id > 0)
  //{
  //  // parent
  //  while (true)
  //  {

  //    std::cout << "I am parent, pid: " << getpid() << ", ppid:" << getppid() << std::endl;
  //    sleep(2);
  //  }
  //}
  //else
  //{
  //  // TODU
  //}

  //sleep(1);

  //return 0;
}

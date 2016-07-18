#include <stdlib.h>
#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <regex>

using namespace std;

int main(int argc, char *argv[]){
  const char *path  = argc <=1 ? "." : argv[1];
  DIR *d = opendir(path);
  if(d==NULL)
    return EXIT_FAILURE;
  for(struct dirent *de = NULL; (de = readdir(d))!=NULL; )
    {
      //      cout<<de->d_name<<endl;
      string tmp(de->d_name);
      for(int i=0; i<tmp.size(); ++i)
	{
	  if(tmp[i]=='//')
	    tmp[i] = '\\';
	}
      

      //      tmp.replace(tmp.find("\\"), sizeof("//"), "//");

      string pathStr(path);

      for(int i=0; i<pathStr.size(); ++i)
	{
	  if(pathStr[i]=='//')
	    pathStr[i] = '\\';
	}
try
  {
      string extension = tmp.substr(tmp.find_last_of('.'));
      if(extension==".webm")
	{
	  cout<<tmp<<endl;
	  if(tmp[0]=='\\')
	    tmp = tmp.substr(1, tmp.size());
	  string commandTobeExecuted = "ffmpeg -i \""+pathStr+"//"+tmp+"\" "+pathStr+"\""+tmp.substr(0, tmp.find_last_of('.'))+".mp3\"";
	  cout<<commandTobeExecuted<<endl;
	    system(commandTobeExecuted.c_str());
	}
  }
 catch(...)
   {
     cout<<"Eror";
   }
    }
  closedir(d);
  return 0;
}

#include <fstream>
#include <mutex>
class LogFileWriter{
private:
	static std::ofstream file;
	static LogFileWriter *instance;
	static std::mutex locker;
	LogFileWriter(){ file.open("log.txt"); }
	
public:
	void writeLine(char content[])const{
		locker.lock();
		file << content;
		locker.unlock();
	}
	static LogFileWriter* getInstance(){
		if (instance == NULL){
			LogFileWriter();
		}
		return instance;
	}
	LogFileWriter(LogFileWriter const&) = delete;
	void operator=(LogFileWriter const&) = delete;
};
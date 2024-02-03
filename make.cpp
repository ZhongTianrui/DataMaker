#define _CRT_SECURE_NO_WARNINGS
#include<fstream>
#include<vector>
#include<filesystem>
#include<cstdlib>
#include<random>
#include "includes/json.hpp"
#include "includes/zipfile.hpp"
using namespace std;
using namespace std::filesystem;
using namespace miniz_cpp;
using json = nlohmann::json;

random_device rd;

struct random{
    default_random_engine rdm;
    uniform_int_distribution<> dis;
    
    random(int low, int up){ rdm=default_random_engine(rd()); dis=uniform_int_distribution(low, up); }
    int operator() (){
        return dis(rdm);
    }
};

string strRand(int length) {			// length: �����ַ����ĳ���	
    string buffer;						// buffer: ���淵��ֵ
    string charset="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    random rdm(0, charset.size() - 1);
    
    for (int i = 0; i < length; i++) {
        buffer += charset[rdm()];
    }
    return buffer;
}

int _execute(string cmd){
    return system(cmd.c_str());
}
#ifdef _WIN32

int execute(string name){
    return _execute(name + ".exe");
}
#else
int execute(string name){
    return _execute("./"+name);
}
#endif


void generate(string fn, int id, string exename, string std, zip_file& zf){
	string inp = fn + "/" + "in" + to_string(id) + ".in", out = fn + "/" + "out" + to_string(id) + ".out";
	freopen(inp.c_str(), "w", stdout);
	execute(exename); 
	freopen(inp.c_str(), "r", stdin);
	freopen(out.c_str(), "w", stdout);
	execute(std);	
	    zf.write(inp);
	    zf.write(out);
}

vector <int> begin, end;

int main() {
	ios::sync_with_stdio(false);
	ofstream fout("log.log");
	//ifstream finname("config/Name.txt"), finnum("config/Number.txt"), finbind("config/bind.txt"), finexe("config/exe.txt"), findata("config/data.txt");
	ifstream config_file("config.json");
	json config = json::parse(config_file);
	string fn=config["name"];
	if (fn == "random") {
		fn = strRand(10);
	}else{
	    fn = "data-"+fn;
	}
	create_directories(fn);
	fout.flush();
	int subtask=config["enable_subtask"];
	zip_file zf;
	
	int amount=0;
	if (!subtask) {
		string exename=config["exename"];
		
		amount=config["test_amount"];
		for (int i = 1; i <= amount; i ++) {
			generate(fn, i, exename, config["std"], zf);
			fout << i << ".out/.in Maked\n";
		}
	} else {
		int cnt = 0;
		string exename;
		ofstream off(fn + "\\config.yml");
		int T=config["test_amount"];
		int lasttask = 100 % T;
		json task_config = config["subtasks"];
		
		for(int t=0;t<T;t++){
			int begin = task_config[t]["begin"], end = task_config[t][end];
			exename = task_config[t]["exename"];
			for (int i=begin; i <= end; i ++){
				string s = fn + "/" + "in" + to_string(i) + ".in", s2 = fn + "/" + "out" + to_string(i) + ".out";
			    generate(fn, i, exename, config["std"], zf);
				off << "in"<< i << ".in:\n";
				off << "  subtaskId: " << cnt << "\n";
				if (cnt >= T - lasttask) off << "  score: " << 100 / T + 1 << "\n";
				else off << "  score: " << 100 / T << "\n";
				off << "\n";
				fout << i << ".out/.in Maked\n";
			}
			cnt++;
		}
		
		zf.write(fn+"\\config.yml");
	}
	zf.save(fn+".zip");
	
	//_execute("zip -r -q -j " + fn + ".zip " + fn);
}

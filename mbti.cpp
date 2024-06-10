#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct PersonalityType { 
    string type;
    string description;
};

struct Question {  
    string prompt;
    int answer;
};

struct Person { 
    string name;
    PersonalityType personality;
    vector<Question*> answers;  

    void takeMBTITest(const Question test[20]) { 
        for (int i = 0; i < 20; ++i) {
            int userAnswer;
            system("CLS");
            x:
            cout << test[i].prompt << "\n1. Tidak Setuju \n2. Kurang Setuju \n3. Netral \n4. Setuju \n5. Sangat Setuju \nJawaban anda: ";
            cin >> userAnswer;
            if (userAnswer < 1 || userAnswer > 5) {
                cout << "Input jawaban yang sesuai (1-5)!\n";
                goto x;
            }
            Question* ans = new Question{test[i].prompt, userAnswer};  
            answers.push_back(ans);
        }
    }

    void determinePersonalityType() {
        int a = 0, b = 0, c = 0, d = 0;
        for (int i = 0; i < answers.size(); ++i) {
            switch (i % 4) {
                case 0: a += answers[i]->answer; break;
                case 1: b += answers[i]->answer; break;
                case 2: c += answers[i]->answer; break;
                case 3: d += answers[i]->answer; break;
            }
        }

        personality.type += (a <= 12) ? "I" : "E";
        personality.type += (b <= 12) ? "N" : "S";
        personality.type += (c <= 12) ? "T" : "F";
        personality.type += (d <= 12) ? "P" : "J";

        personality.description += (a <= 12) ? "Introverts: Anda cenderung lebih introvert, memilih refleksi internal, dan menemukan energi dari waktu sendiri." : "Extroverts: Anda cenderung lebih ekstrovert, terbuka secara sosial, dan menemukan energi dari interaksi dengan orang lain.";
        personality.description += (b <= 12) ? "\nIntuitives: Anda cenderung lebih intuitif, melihat gambaran besar, dan lebih suka konsep dan ide." : "\nSensors: Anda cenderung lebih penginderaan, fokus pada fakta konkret dan pengalaman nyata.";
        personality.description += (c <= 12) ? "\nThinkers: Anda cenderung lebih berpikir, mengambil keputusan dengan logika dan analisis objektif." : "\nFeelers: Anda cenderung lebih merasa, mempertimbangkan nilai-nilai personal dan dampak emosional.";
        personality.description += (d <= 12) ? "\nPerceivers: Anda cenderung lebih fleksibel, terbuka terhadap perubahan, dan menyukai pilihan yang beragam.\n" : "\nJudgers: Anda cenderung lebih terstruktur, merencanakan ke depan, dan menghargai ketertiban.\n";
    }

    string generatePatternI(int height, int width) {
        string pattern = "";
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (i == 0 || j == width / 2 || i == height - 1) {
                    pattern += "=";
                } else {
                    pattern += " ";
                }
            }
            pattern += "\n";
        }
        return pattern;
    }

    string generatePatternE(int height, int width) {
        string pattern = "";
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (i == 0 || i == height / 2 || j == 0 || i == height - 1) {
                    pattern += "=";
                } else {
                    pattern += " ";
                }
            }
            pattern += "\n";
        }
        return pattern;
    }

    string generatePatternN(int height, int width) {
        string pattern = "";
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; ++j) {
                if (j == 0 || j == width - 1 || i == j) {
                    pattern += "=";
                } else {
                    pattern += " ";
                }
            }
            pattern += "\n";
        }
        return pattern;
    }

    string generatePatternS(int height, int width) {
        string pattern = "";
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; ++j) {
                if (i == 0 || i == height / 2 || i == height - 1) {
                    pattern += "=";
                } else if (j == 0 && i < height / 2) {
                    pattern += "=";
                } else if (j == width - 1 && i > height / 2) {
                    pattern += "=";
                } else {
                    pattern += " ";
                }
            }
            pattern += "\n";
        }
        return pattern;
    } 

    string generatePatternT(int height, int width) { 
        string pattern = "";
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; ++j) {
                if (i == 0 || j == width / 2) {
                    pattern += "=";
                } else {
                    pattern += " ";
                }
            }
            pattern += "\n";
        }
        return pattern;
    }

    string generatePatternF(int height, int width) {
        string pattern = "";
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; ++j) {
                if (i == 0 || i == height / 2 || j == 0) {
                    pattern += "=";
                } else {
                    pattern += " ";
                }
            }
            pattern += "\n";
        }
        return pattern;
    }

    string generatePatternP(int height, int width) {
    string pattern = "";
    for (int i = 0; i < height; i++) {
        if (i == 0 || i == height / 2) {
            for (int j = 0; j < width; ++j) {
                pattern += "=";
            }
        } else {
            pattern += "=";
            for (int j = 1; j < width; ++j) {
                if (j == width - 1 && i <= height / 2) {
                    pattern += "=";
                } else {
                    pattern += " ";
                }
            }
        }
        pattern += "\n";
    }
    return pattern;
}

    string generatePatternJ(int height, int width) {
        string pattern = "";
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; ++j) {
                if ((i == 0) || (i > 0 && i < height - 1 && j == width / 2) || (i == height - 1 && j <= width / 2)) {
                    pattern += "=";
                } else {
                    pattern += " ";
                }
            }
            pattern += "\n"; 
        }
        return pattern;
    }

    string combinePatterns(const string& mbtiType, int height, int width) {
        vector<string> patterns;
        for (char c : mbtiType) {
            switch (c) {
                case 'I': patterns.push_back(generatePatternI(height, width)); break;
                case 'E': patterns.push_back(generatePatternE(height, width)); break;
                case 'N': patterns.push_back(generatePatternN(height, width)); break;
                case 'S': patterns.push_back(generatePatternS(height, width)); break;
                case 'T': patterns.push_back(generatePatternT(height, width)); break;
                case 'F': patterns.push_back(generatePatternF(height, width)); break;
                case 'P': patterns.push_back(generatePatternP(height, width)); break;
                case 'J': patterns.push_back(generatePatternJ(height, width)); break;
                default:
                break;
            }
        }

        string combinedPattern = "";
        for (int i = 0; i < height; ++i) {
            for (const string& pattern : patterns) {
                combinedPattern += pattern.substr(i * (width + 1), width) + "  ";
            }
            combinedPattern += "\n";
        }
        return combinedPattern;
    }

    void displayPersonalityType() { 
        int height = 5;
        int width = 7;

        string pattern = combinePatterns(personality.type, height, width);
        cout << "Personality Type for " << name << ": \n" << pattern << "\n" << personality.description << endl;
               system("pause");
    }
};

void garisHorizontal(int maxLength) {
    cout << string(maxLength + 10, '=') << endl;
}

void tabelHasil(const vector<Person*>& people) {
    int maxLength = 0;

    for (const auto& person : people) {
        if (person->name.length() > maxLength) {
            maxLength = person->name.length();
        }
    }

    system("CLS");
    garisHorizontal(maxLength);
    cout << "| " << left << setw(maxLength + 2) << "Name" << "Type" << " |\n";
    garisHorizontal(maxLength);

    for (const auto& person : people) {
        cout << "| " << left << setw(maxLength + 2) << person->name << person->personality.type << " |\n";
    }

    garisHorizontal(maxLength);
    system("pause");
}

void garis() {
    cout << string(70, '=') << endl;
}

void welcomeMessage() { 
    garis();
    cout << "                   Selamat Datang di Tes MBTI ^-^" << endl;
    garis();
    cout << "\n   Tes ini akan membantu Anda menemukan tipe kepribadian Anda." << endl;
    cout << "   Jawablah setiap pertanyaan dengan jujur untuk hasil yang akurat." << endl;
    cout << endl;
}

void UcapanTerimaKasih() {
    cout << "\n";
    garis();
    cout << "                  Terima Kasih, have a nice day ^_^" << endl;
    garis();
    cout << "\n";
} 

int main() {
    vector<Person*> people;
    int n;

    Question test[20] = {
        {"Ketika saya menghadiri sebuah acara sosial yang besar, saya merasa bersemangat dan energik.", 0},
        {"Ketika menghadapi masalah, saya mencari solusi yang praktis dan dapat segera diterapkan.", 0},
        {"Saya mempertimbangkan perasaan dan nilai-nilai pribadi untuk membuat keputusan.", 0},
        {"Saya lebih suka memiliki jadwal yang teratur dan mengikutinya dengan disiplin.", 0},
        {"Saya Menghabiskan waktu bersama teman-teman atau keluarga dalam kelompok besar.", 0},
        {"Saya lebih suka informasi yang konkret, detail, dan spesifik.", 0},
        {"Ketika berhadapan dengan konflik, Saya lebih memikirkan perasaan orang lain dan mencari cara untuk menjaga harmoni.", 0},
        {"Saya lebih suka menyelesaikan tugas secepat mungkin dan menghindari penundaan.", 0},
        {"Ketika bekerja dalam kelompok, saya lebih suka berbicara dan berinteraksi dengan anggota kelompok lainnya secara aktif.", 0},
        {"Ketika mengingat sesuatu, saya cenderung mengingat detail spesifik dan fakta yang terjadi.", 0},
        {"Saya menilai keberhasilan suatu proyek dari, bagaimana proyek tersebut mempengaruhi orang-orang yang terlibat.", 0},
        {"Saya merencanakan semua liburan dengan detail dari jauh-jauh hari dan mengikuti rencana tersebut.", 0},
        {"Saya mengisi ulang energi dengan berkumpul bersama teman-teman atau melakukan aktivitas sosial.", 0},
        {"Dalam merencanakan masa depan, saya merencanakan langkah-langkah yang jelas dan realistis.", 0},
        {"Dalam bekerja dengan orang lain, yang lebih penting bagi saya membangun hubungan yang baik dan mendukung.", 0},
        {"Saya merasa lebih nyaman ketika memiliki struktur dan aturan yang jelas.", 0},
        {"Saya merespon situasi yang baru atau tidak dikenal dengan antusias dan segera berinteraksi dengan orang-orang.", 0},
        {"Saya lebih suka mematuhi metode yang telah terbukti dan familiar.", 0},
        {"Saya merasa tersinggung jika kritik tersebut tidak mempertimbangkan perasaan saya.", 0},
        {"Ketika bekerja dalam proyek kelompok, saya lebih suka mengorganisir tugas dan memastikan semua berjalan sesuai rencana.", 0}
    };

    system("CLS");
    welcomeMessage();
    garis();
    cout << "Enter the number of people taking the MBTI test: "; 
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string name;
        system("CLS");
        cin.ignore();
        cout << "Enter name for person " << i + 1 << ": ";
        getline(cin, name); 

        Person* person = new Person{name}; 
        person->takeMBTITest(test);
        person->determinePersonalityType();
        system("CLS");
        person->displayPersonalityType(); 
        cout << endl;
        people.push_back(person);
    }
    tabelHasil(people); 
    UcapanTerimaKasih();
    return 0;
}
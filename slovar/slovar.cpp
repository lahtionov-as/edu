// slovar.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore(); // пропускаем символ новой строки после числа N

	// Словарь: латинское слово -> множество английских слов
	map<string, set<string>> latinToEnglish;

	for (int i = 0; i < n; i++) {
		string line;
		getline(cin, line);

		// Находим разделитель " - "
		size_t pos = line.find(" - ");
		string english = line.substr(0, pos);
		string rest = line.substr(pos + 3);

		// Разбираем список латинских переводов, разделённых ", "
		size_t start = 0;
		while (true) {
			size_t comma = rest.find(", ", start);
			string latin;
			if (comma == string::npos) {
				latin = rest.substr(start);
			}
			else {
				latin = rest.substr(start, comma - start);
			}
			// Добавляем английское слово в множество для данного латинского
			latinToEnglish[latin].insert(english);

			if (comma == string::npos) break;
			start = comma + 2; // пропускаем ", "
		}
	}

	// Выводим количество латинских слов
	cout << latinToEnglish.size() << "\n";

	// Выводим словарь: ключи уже отсортированы (map),
	// значения в set также отсортированы
	for (const auto& pair : latinToEnglish) {
		cout << pair.first << " - ";
		bool first = true;
		for (const string& eng : pair.second) {
			if (!first) cout << ", ";
			cout << eng;
			first = false;
		}
		cout << "\n";
	}

	return 0;
}

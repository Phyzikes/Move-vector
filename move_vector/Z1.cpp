#include <iostream>
#include <vector>
//#include <chrono> // для большей рандомизации

// Объявляем необходимые параметры
int frame_width;
int frame_height;
int pic_width;
int pic_height;
int pic_x;
int pic_y;
// Наш единственный массив
std::vector<std::vector<int>> frame;
// Подфункция для вывода (чтоб дважды не дублировать)
void showFrame() {
	for (int i = 0; i < frame_height; i++) {
		for (int j = 0; j < frame_width; j++) {
			std::cout << frame[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "\n";
}

int main()
{
	// ВВОДИМ НАЧАЛЬНЫЕ ДАННЫЕ //////////////////////
	// Вводим ширину фрейма
	while (true) {
		std::cout << "Enter frame_width:\t";
		std::cin >> frame_width;
		if (std::cin.fail() || frame_width <= 0) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "No valid input! Try again.\n";
		}
		else {
			std::cin.ignore(32767, '\n');
			break;
		}
	}
	// Вводим высоту фрейма + проверям на корректность ввода
	while (true) {
		std::cout << "Enter frame_height:\t";
		std::cin >> frame_height;
		if (std::cin.fail() || frame_height <= 0) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "No valid input! Try again.\n";
		}
		else {
			std::cin.ignore(32767, '\n');
			break;
		}
	}
	// Проверяем случай, если изображение такого же размера, как и фрейм
	do {
		// Вводим ширину изображения + проверям на корректность ввода
		while (true) {
			std::cout << "Enter pic_width:\t";
			std::cin >> pic_width;
			if (std::cin.fail() || pic_width <= 0) {
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "No valid input! Try again.\n";
			}
			else if (pic_width > frame_width) {
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "The frame is not enough for this pic! Try again!\n";
			}
			else {
				std::cin.ignore(32767, '\n');
				break;
			}
		}
		// Вводим высоту изображения + проверям на корректность ввода
		while (true) {
			std::cout << "Enter pic_height:\t";
			std::cin >> pic_height;
			if (std::cin.fail() || pic_height <= 0) {
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "No valid input! Try again.\n";
			}
			else if (pic_height > frame_height) {
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "The frame is not enough for this pic! Try again!\n";
			}
			else {
				std::cin.ignore(32767, '\n');
				break;
			}
		}
		if (frame_width == pic_width && frame_height == pic_height) {
			std::cout << "Your pic has the same size as a frame! Try again!\n";
		}
	} while ((frame_width == pic_width && frame_height == pic_height));
	// Проверяем, есть ли какое-то смещение
	do {
		// Вводим смещение по ширине + проверям на корректность ввода
		while (true) {
			std::cout << "Enter pic_x:\t";
			std::cin >> pic_x;
			if (std::cin.fail() || pic_x < 0) {
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "No valid input! Try again.\n";
			}
			else if (pic_x > frame_width - pic_width) {
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "Offset you pic out of frame! Try again!\n";
			}
			else {
				std::cin.ignore(32767, '\n');
				break;
			}
		}
		// Вводим смещение по высоте + проверям на корректность ввода
		while (true) {
			std::cout << "Enter pic_y:\t";
			std::cin >> pic_y;
			if (std::cin.fail() || pic_y < 0) {
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "No valid input! Try again.\n";
			}
			else if (pic_y > frame_height - pic_height) {
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "Offset you pic out of frame! Try again!\n";
			}
			else {
				std::cin.ignore(32767, '\n');
				break;
			}
		}
		if (pic_x == 0 && pic_y == 0) {
			std::cout << "Your pic is already in left corner! Try again!\n";
		}
	} while ((pic_x == 0 && pic_y == 0));

	// Блок 1. Забиваем массив (создаем фрейм)
	//srand(static_cast<unsigned int>(time(0))); // для большей рандомизации чисел
	for (int i = 0; i < frame_height; i++) {
		std::vector<int> temp;
		for (int j = 0; j < frame_width; j++) {
			temp.push_back(rand()%100); //для прощего отображения возьмем числа поменьше
		}
		frame.push_back(temp);
	}

	// Блок 2. Показываем начальный фрейм - Source
	showFrame();

	// Проверочный блок. Получаем изображение
	/*
	for (int i = 0; i < pic_height; i++) {
		for (int j = 0; j < pic_width; j++) {
			std::cout << frame[i+pic_y][j+pic_x] << "\t";
		}
		std::cout << std::endl;
	}
	*/

	// Блок 3. Блок перестановки (сдвига в угол)
	int temp;
	for (int i = 0; i < pic_height; i++) {
		for (int j = 0; j < pic_width; j++) {
			temp = frame[i][j];
			frame[i][j] = frame[i+pic_y][j+pic_x];
			frame[i + pic_y][j + pic_x] = temp;
		}
	}
	
	// Блок 4. Показываем конечный фрейм - Destination
	showFrame();
	
	// Просто для открытого окна:)
	std::cout << "Press 'y' if you like it!\t";
	std::cin >> temp;
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// Heap oluşturmak için yardımcı fonksiyonlarımız
// (arr:Düzenlenecek dizimiz, n:Dizinin boyutu, i:Kök düğüm indeksi)
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // En büyük elemanı kök olarak ayarlarız
    int left = 2 * i + 1; // Sol çocuk indeksimiz
    int right = 2 * i + 2; // Sağ çocuk indeksimiz

    // Sol çocuk kökten büyük ise
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Sağ çocuk şu anki en büyükten büyük ise
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // En büyük eleman kök değil ise
    if (largest != i) {
        swap(arr[i], arr[largest]); // Elemanları değiştirip
        
        // Etkilenen alt ağacı tekrar düzenleriz
        heapify(arr, n, largest);
    }
}

// Heap Sort ana fonksiyonumuz
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Max heap oluştur (diziyi heap yapısına çevirir)
    // Son yaprak olmayan düğümden başlayarak geriye gideriz
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap'ten elemanları tek tek çıkarırız
    for (int i = n - 1; i > 0; i--) {
        // Kök (en büyük eleman) ile son elemanı değiştiririz
        swap(arr[0], arr[i]);
        
        // Azaltılmış heap'i tekrar düzenleriz
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr;
    int n, num;

    // Kullanıcıdan eleman sayısını alırız
    cout << "Kac eleman gireceksiniz? ";
    cin >> n;

    // Kullanıcıdan elemanları alırız
    cout << n << " tane sayi giriniz:\n";
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }

    // Sıralama öncesi diziyi gösteririz
    cout << "\nSiralama oncesi dizi: ";
    for (int num : arr) {
        cout << num << " ";
    }

    // Heap Sort uygulaması
    heapSort(arr);

    // Sıralama sonrası diziyi gösterir
    cout << "\nSiralama sonrasi dizi: ";
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
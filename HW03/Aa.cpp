#include const char Classismi[] = "pencere"; // gelen mesajları işleyen kısım LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)  { switch(msg) { case WM_CLOSE: DestroyWindow(hwnd); break; case WM_DESTROY: PostQuitMessage(0); break; default: return DefWindowProc(hwnd, msg, wParam, lParam); } return 0;   } int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)  { WNDCLASSEX wc; HWND hwnd; MSG Msg; //birinci adım: Pencere özelliklerini belirten bir sınıf değişkeni tanımlanıyor wc.cbSize = sizeof(WNDCLASSEX); wc.style = 0; wc.lpfnWndProc = WndProc; wc.cbClsExtra = 0; wc.cbWndExtra = 0; wc.hInstance = hInstance; wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); wc.hCursor = LoadCursor(NULL, IDC_ARROW); wc.hbrBackground = (HBRUSH)(COLOR_WINDOW); wc.lpszMenuName = NULL; wc.lpszClassName = Classismi; wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION); if(!RegisterClassEx(&wc)) { MessageBox(NULL, "Pencere tanımlama hatası!", "Hata!", MB_ICONEXCLAMATION | MB_OK); return 0; } // ikinci adım pencere oluşturma hwnd = CreateWindow(Classismi,"Pencere başlığı",WS_OVERLAPPEDWINDOW, 200, 200, 300, 200,NULL, NULL, hInstance, NULL); ShowWindow(hwnd, SW_SHOW); UpdateWindow(hwnd); // üçüncü adım: mesajların alınması ve ayrılması while(GetMessage(&Msg, NULL, 0, 0) > 0) { TranslateMessage(&Msg); DispatchMessage(&Msg); } return Msg.wParam; }
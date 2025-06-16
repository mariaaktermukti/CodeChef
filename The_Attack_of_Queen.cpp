#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) 
    {
        int n, x, y;
        cin >> n >> x >> y;
        
        int horizontal = 2 * (n - 1);
        int diagonal = 0;
        diagonal = diagonal+  min(x - 1, y - 1);
        diagonal = diagonal+ min(x - 1, n - y);
        diagonal = diagonal+ min(n - x, y - 1);
        diagonal = diagonal+ min(n - x, n - y);
        
        cout << horizontal + diagonal << endl;
    }
    
    return 0;
}
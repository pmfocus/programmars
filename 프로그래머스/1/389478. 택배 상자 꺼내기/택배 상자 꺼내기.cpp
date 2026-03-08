#include <iostream>
#include <vector>

using namespace std;

int get_column(int target, int w) {
    int row = (target - 1) / w;
    int pos = (target - 1) % w; 
    
    if (row % 2 == 0) {
        return pos;
    } else {
        return (w - 1) - pos;
    }
}

int get_num_at(int r, int c, int w) {
    if (r % 2 == 0) {
        return r * w + c + 1;
    } else {
        return r * w + (w - 1 - c) + 1;
    }
}

int solution(int n, int w, int num) {
    int count = 0;
    
    int start_row = (num - 1) / w;
    int target_col = get_column(num, w);
    
    int max_row = (n - 1) / w;
    
    for (int r = start_row; r <= max_row; r++) {
        int current_num = get_num_at(r, target_col, w);
        
        if (current_num <= n) {
            count++;
        }
    }
    
    return count;
}
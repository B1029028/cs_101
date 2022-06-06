#include <iostream>

using namespace std;

class MMmanger{
    private:
        int m_Max_Capacity;
        int m_Current_Capacity;
        int** m_allocMem;
        int* m_pGmem;
    public:
        MMmanger(int max_capacity = 10) {
            m_Max_Capacity = max_capacity;
            m_Current_Capacity = max_capacity;
            m_pGmem = (int*)calloc(max_capacity, sizeof(int));
            m_allocMem = (int**)calloc(max_capacity, sizeof(int*));
        }
        ~MMmanger() {
            free(m_allocMem);
            free(m_pGmem);
        }
        void print_calloc_array (int flag = 0, int size){
            for (int i = 0; i<size; i++) {
                (m_allocMem[i]) ? cout << "1":cout << "0";
            }
            if(!flag) {
                cout << " <- Out of space";
            }
            cout << "\n";
        }
        int* calloc_MM(int size) {
            int av_size = 0;
            int index;
            for (index = 0; index < m_Max_Capacity; index++) {
                if (!m_allocMem[index]) {
                    av_size++;
                }
                else {
                    av_size = 0;
                }

                if(av_size == size) {
                    index -= size-1;
                    break;
                }
            }
            if (av_size < size) {
                print_calloc_array(0, m_Max_Capacity);
                return NULL;
            }
            for (int i = 0; i < size; i++) {
                m_allocMem[index+i] = &m_pGmem[index];
            }
            print_calloc_array(1);
            return &m_pGmem[index];
        }
        void free_MM(int* p) {
            for (int i = 0; i < m_Max_Capacity; i++) {
                if (m_allocMem[i] == p) {
                    m_allocMem[i] = NULL;
                }
            }
            print_calloc_array(1, m_Max_Capacity);
        }
        int get_MMCapacity() {

        }
};

int main() {
    MMmanger mmer(10);
    int* p1 = mmer.calloc_MM(1);
    int* p2 = mmer.calloc_MM(2);
    int* p3 = mmer.calloc_MM(3);
    int* p4 = mmer.calloc_MM(4);
    mmer.free_MM(p1);
    mmer.free_MM(p4);
    int* p5 = mmer.calloc_MM(6);
}
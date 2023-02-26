#include <bits/stdc++.h>

using namespace std;
int main()
{
    int number_of_pages, number_of_frames;
    cout << "Enter number of pages: ";
    cin >> number_of_pages;
    cout << "Enter number of frames: ";
    cin >> number_of_frames;
    int pages[number_of_pages], frames[number_of_frames];
    fill(frames, frames + number_of_frames, -1);
    cout << "Enter pages: ";
    int max_of_page_number = 0;
    for (int i = 0; i < number_of_pages; i++)
    {
        cin >> pages[i];
        max_of_page_number = max(max_of_page_number, pages[i]);
    }
    int pageTable[max_of_page_number + 1] = {0}, page_faults = 0;
    for (int i = 0; i < number_of_pages; i++)
    {
        bool isFault = false;
        if (!pageTable[pages[i]])
        {
            isFault = true;
            page_faults++;
            pageTable[pages[i]] = 1;
            int j = 0;
            for (; j < number_of_frames; j++)
                if (frames[j] == -1)
                {
                    frames[j] = pages[i];
                    break;
                }
            if (j == number_of_frames)
            {
                int latest_used = 0, latest_used_index = 0;
                for (int j = 0; j < number_of_frames; j++)
                {
                    int k = i + 1;
                    for (; k < number_of_pages; k++)
                        if (pages[k] == frames[j])
                            break;
                    if (k == number_of_pages)
                    {
                        latest_used = number_of_pages - i;
                        latest_used_index = j;
                        break;
                    }
                    else if (k - i > latest_used)
                    {
                        latest_used = k - i;
                        latest_used_index = j;
                    }
                }
                pageTable[frames[latest_used_index]] = 0;
                frames[latest_used_index] = pages[i];
            }
        }
        cout << pages[i] << " | ";
        for (int j = 0; j < number_of_frames; j++)
        {

            if (frames[j] == -1)
                cout << "x ";
            else
                cout << frames[j] << " ";
        }
        cout << "| ";
        if (isFault)
            cout << "F";
        cout << endl;
    }
    cout << "Page faults: " << page_faults;
}
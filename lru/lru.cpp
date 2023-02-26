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
    int pageCount[max_of_page_number + 1] = {0}, page_faults = 0;
    for (int i = 0; i < number_of_pages; i++)
    {
        bool isFault = false;
        if (!pageCount[pages[i]])
        {
            isFault = true;
            page_faults++;
            int j = 0;
            for (; j < number_of_frames; j++)
                if (frames[j] == -1)
                {
                    frames[j] = pages[i];
                    break;
                }
            if (j == number_of_frames)
            {
                int most_frequent_page = 0;
                for (int j = 1; j < number_of_frames; j++)
                {
                    if (pageCount[frames[j]] > pageCount[frames[most_frequent_page]])
                        most_frequent_page = j;
                }
                pageCount[frames[most_frequent_page]] = 0;
                frames[most_frequent_page] = pages[i];
            }
        }
        else
            pageCount[pages[i]] = 0;
        cout << pages[i] << " | ";
        for (int j = 0; j < number_of_frames; j++)
        {

            if (frames[j] == -1)
                cout << "x ";
            else
            {
                pageCount[frames[j]]++;
                cout << frames[j] << " ";
            }
        }
        cout << "| ";
        if (isFault)
            cout << "F";
        cout << endl;
    }
    cout << "Page faults: " << page_faults;
}
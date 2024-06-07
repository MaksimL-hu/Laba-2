#include <iostream>
#include <string>

using namespace std;

void PrintMenu() {
    cout << "Select action:" << endl;
    cout << "1. Create DynamicArray" << endl;
    cout << "2. Create LinkedList" << endl;
    cout << "3. Create ArraySequence" << endl;
    cout << "4. Create ListSequence" << endl;
    cout << "5. Append item" << endl;
    cout << "6. Prepend item" << endl;
    cout << "7. Insert item at index" << endl;
    cout << "8. Get item" << endl;
    cout << "9. Get first item" << endl;
    cout << "10. Get last item" << endl;
    cout << "11. Get subsequence" << endl;
    cout << "12. Concatenate sequences" << endl;
    cout << "0. Exit" << endl;
}

template <typename T>
void PrintSequence(Sequence<T>* seq) {
    cout << "Sequence: ";

    for (int i = 0; i < seq->GetLength(); ++i) {
        cout << seq->Get(i) << " ";
    }

    cout << endl;
}

int Menu() {
    Sequence<int>* sequence = nullptr;
    int choice, value, index, startIndex, endIndex;

    while (true) {
        PrintMenu();
        cin >> choice;

        switch (choice) 
        {
            case 1: 
            {
                int size = 0;
                sequence = new ArraySequence<int>(new int[size], size);
                cout << "DynamicArray created." << endl;

                break;
            }

            case 2: 
            {
                sequence = new ListSequence<int>();
                cout << "LinkedList created." << endl;

                break;
            }

            case 3: 
            {
                int size;
                cout << "Enter size of ArraySequence: ";
                cin >> size;
                sequence = new ArraySequence<int>(new int[size], size);
                cout << "ArraySequence created." << endl;

                break;
            }

            case 4: 
            {
                sequence = new ListSequence<int>();
                cout << "ListSequence created." << endl;

                break;
            }

            case 5: 
            {
                cout << "Enter value to append: ";
                cin >> value;

                if (sequence) 
                {
                    sequence->Append(value);
                    cout << "Item appended." << endl;
                    PrintSequence(sequence);
                }
                else 
                {
                    cout << "No sequence created yet." << endl;
                }

                break;
            }

            case 6: 
            {
                cout << "Enter value to prepend: ";
                cin >> value;

                if (sequence) 
                {
                    sequence->Prepend(value);
                    cout << "Item prepended." << endl;
                    PrintSequence(sequence);
                }
                else 
                {
                    cout << "No sequence created yet." << endl;
                }

                break;
            }

            case 7: 
            {
                cout << "Enter index and value to insert: ";
                cin >> index >> value;

                if (sequence) 
                {
                    try 
                    {
                        sequence->InsertAt(value, index);
                        cout << "Item inserted at index " << index << "." << endl;
                        PrintSequence(sequence);
                    }
                    catch (const out_of_range& e) 
                    {
                        cout << "Index out of range." << endl;
                    }
                }
                else 
                {
                    cout << "No sequence created yet." << endl;
                }

                break;
            }

            case 8: 
            {
                cout << "Enter index to get item: ";
                cin >> index;

                if (sequence) 
                {
                    try 
                    {
                        cout << "Item at index " << index << ": " << sequence->Get(index) << endl;
                    }
                    catch (const out_of_range& e) {

                        cout << "Index out of range." << endl;
                    }
                }
                else 
                {
                    cout << "No sequence created yet." << endl;
                }

                break;
            }

            case 9: 
            {
                if (sequence) 
                {
                    try 
                    {
                        cout << "First item: " << sequence->GetFirst() << endl;
                    }
                    catch (const out_of_range& e) {
                        cout << "Sequence is empty." << endl;
                    }
                }
                else 
                {
                    cout << "No sequence created yet." << endl;
                }

                break;
            }

            case 10: 
            {
                if (sequence) 
                {
                    try 
                    {
                        cout << "Last item: " << sequence->GetLast() << endl;
                    }
                    catch (const out_of_range& e) 
                    {
                        cout << "Sequence is empty." << endl;
                    }
                }
                else 
                {
                    cout << "No sequence created yet." << endl;
                }

                break;
            }

            case 11: 
            {
                cout << "Enter start and end index for subsequence: ";
                cin >> startIndex >> endIndex;

                if (sequence) 
                {
                    try 
                    {
                        Sequence<int>* subseq = sequence->GetSubsequence(startIndex, endIndex);
                        PrintSequence(subseq);
                        delete subseq;
                    }
                    catch (const out_of_range& e) 
                    {
                        cout << "Index out of range." << endl;
                    }
                }
                else 
                {
                    cout << "No sequence created yet." << endl;
                }

                break;
            }

            case 12: 
            {
                // Пример простого объединения двух последовательностей
                int size;
                cout << "Enter size of the second sequence: ";
                cin >> size;
                int* items = new int[size];
                cout << "Enter items of the second sequence: ";

                for (int i = 0; i < size; ++i)
                {
                    cin >> items[i];
                }

                Sequence<int>* secondSeq = new ArraySequence<int>(items, size);

                if (sequence)
                {
                    Sequence<int>* concatenated = sequence->Concat(secondSeq);
                    cout << "Concatenated sequence: ";
                    PrintSequence(concatenated);
                    delete concatenated;
                }
                else
                {
                    cout << "No sequence created yet." << endl;
                }

                delete secondSeq;
                delete[] items;

                break;
            }

            case 0: 
            {
                delete sequence;

                return 0;
            }

            default:
            {
                cout << "Invalid choice. Please try again." << endl;

                break;
            }
        }

        cout << "\n";
    }
}
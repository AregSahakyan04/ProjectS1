#include <stdio.h>
#include <string.h>



struct CarTradeRecord 
{
    char mark[30];
    char type[30];
    int km;
    char injury[50];
    long price;
    long int phone;
    char username[50];
};

static int p = 0;



void addTrade(struct CarTradeRecord *trades) {
    
    printf("Enter car mark: ");
    scanf("%s", trades[p].mark);

    printf("Enter car type: ");
    scanf("%s", trades[p].type);

    printf("Enter car mileage (in km): ");
    scanf("%d", &trades[p].km);

    printf("Enter any injuries: ");
    scanf("%s", trades[p].injury);

    printf("Enter car price: ");
    scanf("%ld", &trades[p].price);

    printf("Enter seller's phone number: ");
    scanf("%ld", &trades[p].phone);

    printf("Enter seller's username(without space): ");
    scanf("%s", trades[p].username);

    p++;
}

void listRecord(struct CarTradeRecord *trades) {
    
    for (int n = 0; n < p; n++) {
        printf("\nCar Mark: %s\nType: %s\nMileage: %d km\nInjuries: %s\nPrice: $%ld\nPhone: %ld\nUsername: %s\n",
               trades[n].mark, trades[n].type, trades[n].km, trades[n].injury, trades[n].price, trades[n].phone, trades[n].username);
        printf("-----------------------\n");
    }
    
}

int findTradeIndex(struct CarTradeRecord *trades, const char *username) {
    for (int n = 0; n < p; n++) {
        
        if (strcmp(trades[n].username, username) == 0) 
        {
            return n;
        }
        
    }
    
    return -1; // Indicates that the trade with the given username was not found

}

void modifyRecord(struct CarTradeRecord *trades) {
    
    char usernameToModify[50];
    printf("Enter seller's username(without space) to modify: ");
    scanf("%s", usernameToModify);

    int index = findTradeIndex(trades, usernameToModify);
    
    if (index != -1) 
    {
        // Car trade found, perform modifications
        printf("Enter new car type: ");
        scanf("%s", trades[index].type);

        printf("Enter new car mileage (in km): ");
        scanf("%d", &trades[index].km);

        printf("Enter new injuries: ");
        scanf("%s", trades[index].injury);

        printf("Enter new car price: ");
        scanf("%ld", &trades[index].price);

        printf("Enter new seller's phone number: ");
        scanf("%ld", &trades[index].phone);

        printf("Record modified successfully!\n");
    } 
    
    else {
        printf("Car trade with username '%s' not found.\n", usernameToModify);
    }
}

void deleteRecord(struct CarTradeRecord *trades) {
    
    char usernameToDelete[50];
    printf("Enter seller's username to delete: ");
    scanf("%s", usernameToDelete);

    int index = findTradeIndex(trades, usernameToDelete);
    
    if (index != -1) 
    {
        // Car trade found, perform deletion
        for (int i = index; i < p - 1; i++) {
            trades[i] = trades[i + 1];
        }
        
        p--;

        printf("Record deleted successfully!\n");
    }
    else {
        printf("Car trade with username '%s' not found.\n", usernameToDelete);
    }
    
}

void searchRecord(struct CarTradeRecord *trades) {
    
    char usernameToSearch[50];
    
    printf("Enter seller's username to search: ");
    scanf("%s", usernameToSearch);

    int index = findTradeIndex(trades, usernameToSearch);
    
    if (index != -1) {
        // Car trade found, display details
        printf("\nCar Mark: %s\nType: %s\nMileage: %d km\nInjuries: %s\nPrice: $%ld\nPhone: %ld\nUsername: %s\n",
               trades[index].mark, trades[index].type, trades[index].km, trades[index].injury, trades[index].price, trades[index].phone, trades[index].username);
        printf("-----------------------\n");
    }
    else {
        printf("Car trade with username '%s' not found.\n", usernameToSearch);
    }
    
}

int main() {
    
    struct CarTradeRecord trades[10];
    int choice;

    while (1) {
        
        printf("\n\n\n\n\n");
        printf("\t\t\t1. Add Trade\n\t\t\t"
               "2. List Record\n\t\t\t"
               "3. Modify Record\n\t\t\t"
               "4. Delete Record\n\t\t\t"
               "5. Search Record\n\t\t\t"
               "6. Exit\n");
        printf("\n\t\t\tEnter your choice:-> ");
        scanf("%d", &choice);

        switch (choice) {
            
            case 1:
                addTrade(trades);
                break;
            
            case 2:
                listRecord(trades);
                break;
            
            case 3:
                modifyRecord(trades);
                break;
            
            case 4:
                deleteRecord(trades);
                break;
            
            case 5:
                searchRecord(trades);
                break;
            
            case 6:
                return 0;
            
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}


// Written by Emin Ayyıldız
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void display_products(void);
void purchase_product(void);

struct product {
    int id;
    char name[20];
    int price;
    int stock;
    int stock_check;
};

struct product products[] =
{
    {1, "Chocolate", 10, 40},
    {2, "Water    ",  4, 30},
    {3, "Sandwich ", 20, 40},
    {4, "Coke     ", 15, 50},
    {5, "Coffee   ", 18, 50},
    {6, "Biscuit  ", 15, 50},
    {7, "Redbull  ", 20, 50},
};

int product_count = sizeof(products) / sizeof(struct product);

int find_product_index(int id) {
    int product_index = -1;
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            product_index = i;
            break;
        }
    }
    return product_index;
}

void display_products() {
    printf("ID\tName\t\tPrice\tStock\n");
    for (int i = 0; i < product_count; i++) {
        printf("%d\t%s\t%d\t\t%d\n", products[i].id, products[i].name, products[i].price, products[i].stock);
    }
}

void purchase_product() {
    int id, product_index, stock_check;
    printf("Enter product ID: ");
    scanf("%d", &id);
    product_index = find_product_index(id);
    if (product_index == -1) {
        printf("Invalid product ID\n");
        return;
    }
    if (products[product_index].stock <= 0) {
        printf("Product out of stock\n");
        return;
    }
    printf("How many products do you want to buy : ");
    scanf("%d", &stock_check);
    if (stock_check >products[product_index].stock){
        
        printf("INSUFFICIENT STOCK");
    }
    else{
        products[product_index].stock-=stock_check;
        
        printf("Price: %d\n", products[product_index].price*stock_check);
        int payment_method;
        printf("Please select the payment method \n1- Credit Card \n2- CASH\n---> ");
        scanf("%d",&payment_method);
        if (payment_method == 1) {
            printf("Please bring your card closer to the payment screen...\n");
            sleep(3);
            printf("The payment transaction was successful. Thank you. \n");
            sleep(1.5);
            printf("The product is being given.. Please wait.\n");
            sleep(3);
        } else if (payment_method == 2) {
            printf("Your money is being counted... Please wait. \n");
            sleep(2);
            printf("The payment transaction was successful. Thank you. \n");
            sleep(1.5);
            printf("The product is being given.. Please wait. \n");
            
            sleep(3);
        } else {
            printf("Invalid payment method. Please try again. \n");
        }
        
    }
}
int main(void) {
    while (1) {
        int choice;
        printf("\n       *****WELCOME*****\n");
        printf("         *****MENU***** \n\n");
        display_products();
        printf("\n1. Purchase product\n2. Exit\n\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            purchase_product();
        }
        else if (choice == 2){
            printf("Exiting...Please wait. \n");
            sleep(1.5);
            printf("BYE BYE\n");
            exit(0);
        }

        else{
            printf("Invalid choice\n");
        }
    }
}


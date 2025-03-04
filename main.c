#include <item.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index) {
    item_list[index].price = price;
    item_list[index].sku = malloc(strlen(sku) + 1);
    strcpy(item_list[index].sku, sku);
    item_list[index].category = malloc(strlen(category) + 1);
    strcpy(item_list[index].category, category);
    item_list[index].name = malloc(strlen(name) + 1);
    strcpy(item_list[index].name, name);
}

void free_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        free(item_list[i].sku);
        free(item_list[i].category);
        free(item_list[i].name);
    }
    free(item_list);
}

double average_price(Item *item_list, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += item_list[i].price;
    }
    return size > 0 ? sum / size : 0.0;
}

void print_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        printf("Item %d:\n", i + 1);
        printf("Name: %s\n", item_list[i].name);
        printf("SKU: %s\n", item_list[i].sku);
        printf("Category: %s\n", item_list[i].category);
        printf("Price: %.2f\n\n", item_list[i].price);
    }
	printf("Average price of items = %.6f\n", average_price(item_list, size));
}

void search_item(Item *item_list, int size, char *sku) {
    int i = 0;
    while (i < size && strcmp(item_list[i].sku,sku) != 0) {
        i++;
    }
    if (i < size) {
        printf("Item found:\n");
        printf("Name: %s\n", item_list[i].name);
        printf("SKU: %s\n", item_list[i].sku);
        printf("Category: %s\n", item_list[i].category);
        printf("Price: %.2f\n", item_list[i].price);
    } else {
        printf("Item not found.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <SKU>\n", argv[0]);
        return 1;
    }
    char *search_sku = argv[1];
    
    int size = 5;
    Item *item_list = malloc(size * sizeof(Item));
    
    add_item(item_list, 1.99, "12345", "Dairy", "Cheese", 0);
    add_item(item_list, 2.97, "99595", "Bakery", "White Sandwich Bread", 1);
    add_item(item_list, 3.99, "02351", "Produce", "Mustard", 2);
    add_item(item_list, 5.99, "09876", "Meat", "Bologna", 3);
    add_item(item_list, 4.99, "45678", "Drinks", "Diet Coke", 4);
    
    search_item(item_list, size, search_sku);
    
    free_items(item_list, size);
   
 return 0;
}

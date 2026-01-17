#include<stdio.h>
#include<string.h>

struct date {
    int day, month, year;
};

struct product {
    char name[40];
    char type[20];
    int stock;
    int price;
    struct date added;

};

struct customer
{
    int id;
    char name[100];
    char product[100];
    char category[100];
    int customer_qty;
    double price;
    char contact[100];
    char address[100];

};

struct supplier
{
    int id;
    char name[100];
    char contact[100];
    char address[100];
    char supplytype[100];
    char lastsupplydate[100];
    char active[10];
};

struct employee
{
    int id;
    char name[100];
    char position[50];
    char contact[100];
    char address[100];
    char active[10];
};

struct product products[1000];
int productcount = 0;

struct customer customers[1000];
int customercount = 0;

struct supplier suppliers[1000];
int suppliercount = 0;

struct employee employees[1000];
int employeecount = 0;

int flag = 0;

void clearbuffer()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF );

}

void clearBuffer(FILE *fp)
{
    int c;
    while ((c = fgetc(fp)) != '\n' && c != EOF);

}

void addProduct()
{

    struct product p;

    printf("\nEnter name: ");
    fgets(p.name, sizeof(p.name),stdin);
    p.name[strcspn(p.name,"\n")]='\0';

    printf("\nEnter type: ");
    fgets(p.type, sizeof(p.type),stdin);
    p.type[strcspn(p.type,"\n")]='\0';

    printf("\nEnter stock: ");
    scanf("%d", &p.stock);
    clearbuffer();

    printf("\nEnter price: ");
    scanf("%d", &p.price);
    clearbuffer();

    printf("\nEnter added date (dd mm yyyy): ");
    scanf("%d %d %d", &p.added.day, &p.added.month, &p.added.year);

    products[productcount]=p;
    productcount++;

    FILE *fp;
    fp = fopen("E://AhnafFiles//products.txt","a");

    if(fp == NULL)
    {
        printf("Nothing to show\n");
        return;
    }

    fprintf(fp,"%s\n %s\n %d\n %d\n %d %d %d\n",p.name,p.type,p.stock,p.price,p.added.day,p.added.month,p.added.year);

    fclose(fp);

    printf("\nProduct added successfully!\n");

}

void viewProducts()
{
    struct product p;

    FILE *fp;

    fp = fopen("E://AhnafFiles//products.txt","r");

    if(fp == NULL)
    {
        printf("Nothing To Show\n");
        return;
    }

   productcount = 0;

while(fgets(p.name, sizeof(p.name), fp) != NULL)
{
    p.name[strcspn(p.name,"\n")] = '\0';

    if(fgets(p.type, sizeof(p.type), fp) == NULL)
    break;
    p.type[strcspn(p.type,"\n")] = '\0';

    if(fscanf(fp,"%d", &p.stock) != 1)
    break;
    clearBuffer(fp);

    if(fscanf(fp,"%d", &p.price) != 1)
    break;
    clearBuffer(fp);

    if(fscanf(fp,"%d %d %d", &p.added.day, &p.added.month, &p.added.year) != 3)
    break;
    clearBuffer(fp);

    products[productcount] = p;
    productcount++;

}


    printf("\n====== PRODUCT LIST ======\n");
    for (int i = 0; i < productcount; i++)
        {
        printf("\nName: %s\nType: %s\nPrice: %d\nStock: %d\nDate: %02d-%02d-%04d\n",
               products[i].name, products[i].type, products[i].price, products[i].stock,
               products[i].added.day, products[i].added.month, products[i].added.year);

        }

}

void searchProduct()
{
    struct product p;

    FILE *fp;

    fp = fopen("E://AhnafFiles//products.txt","r");

    if(fp == NULL)
    {
        printf("Nothing to show\n");
        return;
    }

    productcount = 0;

while(fgets(p.name, sizeof(p.name), fp) != NULL)
{
    p.name[strcspn(p.name,"\n")] = '\0';

    if(fgets(p.type, sizeof(p.type), fp) == NULL) break;
    p.type[strcspn(p.type,"\n")] = '\0';

    if(fscanf(fp,"%d", &p.stock) != 1) break;
    clearBuffer(fp);

    if(fscanf(fp,"%d", &p.price) != 1) break; // if price is int
    clearBuffer(fp);

    if(fscanf(fp,"%d %d %d", &p.added.day, &p.added.month, &p.added.year) != 3) break;
    clearBuffer(fp);

    products[productcount] = p;
    productcount++;

}


    char name[40];
    printf("\nEnter product name to search: ");
    fgets(name,sizeof(name),stdin);
    name[strcspn(name,"\n")]='\0';

    int found = 0;

    for (int i = 0; i < productcount; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("\nFound:\nName: %s\nType: %s\nPrice: %d\nStock: %d\nDate: %02d-%02d-%04d\n",
                   products[i].name, products[i].type, products[i].price, products[i].stock,
                   products[i].added.day, products[i].added.month, products[i].added.year);

            found++;

            break;

        }

    }

    if(found == 0)
    {
    printf("\nProduct not found.\n");
    return;
    }

}

void updateProduct()
{
    struct product p;

    int found = 0;

    FILE *fp;

    fp = fopen("E://AhnafFiles//products.txt","r");

    if(fp == NULL)
    {
        printf("Nothing to show\n");
        return;
    }

   productcount = 0;

while(fgets(p.name, sizeof(p.name), fp) != NULL)
{
    p.name[strcspn(p.name,"\n")] = '\0';

    if(fgets(p.type, sizeof(p.type), fp) == NULL) break;
    p.type[strcspn(p.type,"\n")] = '\0';

    if(fscanf(fp,"%d", &p.stock) != 1) break;
    clearBuffer(fp);

    if(fscanf(fp,"%d", &p.price) != 1) break; // if price is int
    clearBuffer(fp);

    if(fscanf(fp,"%d %d %d", &p.added.day, &p.added.month, &p.added.year) != 3) break;
    clearBuffer(fp);

    products[productcount] = p;
    productcount++;
}


    char name[40];
    printf("\nEnter product to update: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name,"\n")]='\0';

    for (int i = 0; i < productcount; i++) {
        if (strcmp(products[i].name, name) == 0)
        {
            printf("\nCurrent info:\n");
            printf("Name: %s\nType: %s\nPrice: %d\nStock: %d\nDate: %02d-%02d-%04d\n",
                   products[i].name, products[i].type, products[i].price, products[i].stock,
                   products[i].added.day, products[i].added.month, products[i].added.year);

            printf("\nEnter new type: ");
            fgets(products[i].type, sizeof(products[i].type),stdin);
            products[i].type[strcspn(products[i].type,"\n")]='\0';
            printf("\nEnter new stock: ");
            scanf("%d", &products[i].stock);
            clearbuffer();
            printf("\nEnter new price: ");
            scanf("%d", &products[i].price);
            clearbuffer();

            printf("\nProduct updated!\n");

            found++;

            break;

        }

    }

    if(found == 0)
    {
        printf("No product Found\n");
        return;
    }



    fp = fopen("E://AhnafFiles//products.txt","w");

    if(fp == NULL)
    {
        printf("Nothing to show\n");
        return;
    }

    for(int i=0;i<productcount;i++)
    {
        fprintf(fp,"%s\n %s\n %d\n %d\n %d %d %d\n",products[i].name,products[i].type,products[i].stock,products[i].price,products[i].added.day,products[i].added.month,products[i].added.year);
    }

    fclose(fp);

    printf("\nInfo Updated successfully!\n");
}

void deleteProduct()
{
    struct product p;

    int found = 0;

    FILE *fp;

    fp = fopen("E://AhnafFiles//products.txt","r");

    if(fp == NULL)
    {
        printf("Nothing to show\n");
        return;
    }

   productcount = 0;

while(fgets(p.name, sizeof(p.name), fp) != NULL)
{
    p.name[strcspn(p.name,"\n")] = '\0';

    if(fgets(p.type, sizeof(p.type), fp) == NULL) break;
    p.type[strcspn(p.type,"\n")] = '\0';

    if(fscanf(fp,"%d", &p.stock) != 1) break;
    clearBuffer(fp);

    if(fscanf(fp,"%d", &p.price) != 1) break;
    clearBuffer(fp);

    if(fscanf(fp,"%d %d %d", &p.added.day, &p.added.month, &p.added.year) != 3) break;
    clearBuffer(fp);

    products[productcount] = p;
    productcount++;
}

    char name[40];
    printf("\nEnter product to delete: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name,"\n")]='\0';

    for (int i = 0; i < productcount; i++)
    {
        if (strcmp(products[i].name, name) == 0)
        {
            for (int j = i; j < productcount - 1; j++)
                products[j] = products[j + 1];

            productcount--;

            printf("\nProduct deleted.\n");

            found++;

            break;

        }

    }

    if(found == 0)
    {
        printf("Product not found\n");
        return;
    }

    fp = fopen("E://AhnafFiles//products.txt","w");

    if(fp == NULL)
    {
        printf("Nothing to show\n");
        return;
    }

    for(int i=0;i<productcount;i++)
    {
        fprintf(fp,"%s\n %s\n %d\n %d\n %d %d %d\n",products[i].name,products[i].type,products[i].stock,products[i].price,products[i].added.day,products[i].added.month,products[i].added.year);
    }

    fclose(fp);

}

void sellProduct()
{
    struct product p;

    FILE *fp;

    fp = fopen("E://AhnafFiles//products.txt","r");

    if(fp == NULL)
    {
        printf("Nothing to show\n");
        return;
    }

    productcount = 0;

while(fgets(p.name, sizeof(p.name), fp) != NULL)
{
    p.name[strcspn(p.name,"\n")] = '\0';

    if(fgets(p.type, sizeof(p.type), fp) == NULL)
    break;
    p.type[strcspn(p.type,"\n")] = '\0';

    if(fscanf(fp,"%d", &p.stock) != 1)
    break;
    clearBuffer(fp);

    if(fscanf(fp,"%d", &p.price) != 1)
    break;
    clearBuffer(fp);

    if(fscanf(fp,"%d %d %d", &p.added.day, &p.added.month, &p.added.year) != 3)
    break;
    clearBuffer(fp);

    products[productcount] = p;
    productcount++;
}

    fclose(fp);

    char name[40];
    int amount;

    printf("\nEnter product to sell: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name,"\n")]='\0';

    printf("Enter amount to sell: ");
    scanf("%d", &amount);
    clearbuffer();

    for (int i = 0; i < productcount; i++)
    {
        if (strcmp(products[i].name, name) == 0)
            {

            if (products[i].stock >= amount)
            {
                products[i].stock -= amount;

                flag+=amount;

                printf("\nSale successful! Remaining stock: %d\n", products[i].stock);

            }

            else
            {
                printf("\nNot enough stock!\n");

                return;

            }

        }

    }

    fp = fopen("E://AhnafFiles//products.txt","w");

    if(fp == NULL)
    {
        printf("Nothing to show\n");
        return;
    }

    for(int i=0;i<productcount;i++)
    {
        fprintf(fp,"%s\n %s\n %d\n %d\n %d %d %d\n",products[i].name,products[i].type,products[i].stock,products[i].price,products[i].added.day,products[i].added.month,products[i].added.year);
    }

    fclose(fp);

}

int compDate(struct product a, struct product b)
{
    if (a.added.year != b.added.year)
        return a.added.year < b.added.year ? -1 : 1;

    if (a.added.month != b.added.month)
        return a.added.month < b.added.month ? -1 : 1;

    if (a.added.day != b.added.day)
        return a.added.day < b.added.day ? -1 : 1;

    return 0;

}


int compPrice(struct product a, struct product b)
{
    if (a.price < b.price) return -1;
    if (a.price > b.price) return 1;
    return 0;

}


void sortProducts(struct product p[], int n, int (*cmp)(struct product, struct product), int order)
{
    for (int i = 0; i < n - 1; i++)
        {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (cmp(p[j], p[j + 1]) * order > 0)
            {
                struct product temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;

            }

        }

    }

}


void sortMenu()
{

    if (productcount == 0)
    {
        printf("\nNo products to sort.\n");
        return;
    }

    int choice;

    printf("\n-------- Sorting Options --------\n");
    printf("1. Newest first\n");
    printf("2. Oldest first\n");
    printf("3. Highest price\n");
    printf("4. Lowest price\n");
    printf("0. Back\n");

    printf("\nChoice: ");
    scanf("%d", &choice);
    clearbuffer();

    switch (choice)
    {
        case 1: sortProducts(products, productcount, compDate, -1);
        break;

        case 2: sortProducts(products, productcount, compDate, +1);
        break;

        case 3: sortProducts(products, productcount, compPrice, -1);
        break;

        case 4: sortProducts(products, productcount, compPrice, +1);
        break;

        default: return;
    }

    printf("\nSorted successfully!\n");

    printf("\n====== SORTED PRODUCT LIST ======\n");

for (int i = 0; i < productcount; i++)
{
    printf("\nName: %s\nType: %s\nPrice: %d\nStock: %d\nDate: %02d-%02d-%04d\n",
           products[i].name,
           products[i].type,
           products[i].price,
           products[i].stock,
           products[i].added.day,
           products[i].added.month,
           products[i].added.year);
}

}


void productReport()
{
    struct product p;

    if (productcount == 0)
    {
        printf("\nNo products found.\n");
        return;
    }

    FILE *fp;

    fp = fopen("E://AhnafFiles//products.txt","r");

    if(fp == NULL)
    {
        printf("Nothing to show\n");
        return;
    }

    productcount = 0;


while(fgets(p.name, sizeof(p.name), fp) != NULL)
{
    p.name[strcspn(p.name,"\n")] = '\0';

    if(fgets(p.type, sizeof(p.type), fp) == NULL)
    break;
    p.type[strcspn(p.type,"\n")] = '\0';

    if(fscanf(fp,"%d", &p.stock) != 1)
    break;
    clearBuffer(fp);

    if(fscanf(fp,"%d", &p.price) != 1)
    break;
    clearBuffer(fp);

    if(fscanf(fp,"%d %d %d", &p.added.day, &p.added.month, &p.added.year) != 3)
    break;
    clearBuffer(fp);

    products[productcount] = p;
    productcount++;
}

    int totalStock = 0;

    long long totalValue = 0;

    int oldest = 0, newest = 0;

    int highest = 0, lowest = 0;

    for (int i = 0; i < productcount; i++) {
        totalStock += products[i].stock;
        totalValue += (long long)products[i].stock * products[i].price;


        if (compDate(products[i], products[oldest]) < 0) oldest = i;
        if (compDate(products[i], products[newest]) > 0) newest = i;

        if (products[i].price > products[highest].price) highest = i;
        if (products[i].price < products[lowest].price) lowest = i;
    }

    printf("\n==================================================\n");
    printf("                    PRODUCT REPORT\n");
    printf("==================================================\n\n");

    printf("Total Products        : %d\n", productcount);
    printf("Total Stock Units     : %d\n", totalStock);
    printf("Total Inventory Value : %lld\n\n", totalValue);

    printf("--------------------------------------------------------------\n");
    printf("ID   Name                     Type      Qty  Price   Date\n");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < productcount; i++) {
        printf("%-4d %-22s %-10s %-4d %-7d %02d/%02d/%04d\n",
               i+1, products[i].name, products[i].type, products[i].stock, products[i].price,
               products[i].added.day, products[i].added.month, products[i].added.year);
    }

    printf("\n--------------------------------------------------------------\n");
    printf("Oldest Product   : %s (%02d/%02d/%04d)\n",
           products[oldest].name,
           products[oldest].added.day,
           products[oldest].added.month,
           products[oldest].added.year);

    printf("Newest Product   : %s (%02d/%02d/%04d)\n",
           products[newest].name,
           products[newest].added.day,
           products[newest].added.month,
           products[newest].added.year);

    printf("Highest Price    : %s (%d)\n", products[highest].name, products[highest].price);
    printf("Lowest Price     : %s (%d)\n", products[lowest].name, products[lowest].price);

    printf("==============================================================\n");
}

void addcustomer()
{
    struct customer c;
    FILE *fp;

    printf("\nEnter ID : ");
    scanf("%d",&c.id);
    clearbuffer();

    printf("\nEnter Name : ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name,"\n")]='\0';

    printf("\nEnter Product : ");
    fgets(c.product, sizeof(c.product), stdin);
    c.product[strcspn(c.product,"\n")]='\0';

    printf("\nEnter Product Category : ");
    fgets(c.category, sizeof(c.category), stdin);
    c.category[strcspn(c.category,"\n")]='\0';

    printf("\nEnter Quantity : ");
    scanf("%d",&c.customer_qty);

    printf("\nEnter Price : ");
    scanf("%lf",&c.price);
    clearbuffer();

    printf("\nEnter Contact : ");
    fgets(c.contact, sizeof(c.contact), stdin);
    c.contact[strcspn(c.contact,"\n")]='\0';

    printf("\nEnter Address : ");
    fgets(c.address, sizeof(c.address), stdin);
    c.address[strcspn(c.address,"\n")]='\0';

    customers[customercount]=c;
    customercount++;

    fp = fopen("E:\\AhnafFiles\\customer.txt","a");

    if(fp == NULL)
    {
        printf("\nNothing To Show\n");
        return;
    }

    fprintf(fp,"%d\n %s\n %s\n %s\n %d\n %lf\n %s\n %s\n",c.id, c.name, c.product, c.category, c.customer_qty, c.price, c.contact, c.address);
    fclose(fp);

    printf("\nCustomer Added with ID %d !\n",c.id);

}

void viewcustomer()
{
    FILE *fp;

    struct customer c;

    fp = fopen("E:\\AhnafFiles\\customer.txt","r");

    if(fp == NULL)
    {
        printf("\nNo Customer Found!\n");
        return;
    }

   customercount = 0;

while(1)
{
    if(fscanf(fp,"%d",&c.id) != 1)
        break;
    clearBuffer(fp);

    fgets(c.name, sizeof(c.name), fp);
    c.name[strcspn(c.name, "\n")] = '\0';

    fgets(c.product, sizeof(c.product), fp);
    c.product[strcspn(c.product, "\n")] = '\0';

    fgets(c.category, sizeof(c.category), fp);
    c.category[strcspn(c.category, "\n")] = '\0';

    fscanf(fp, "%d",&c.customer_qty);
    clearBuffer(fp);

    fscanf(fp, "%lf",&c.price);
    clearBuffer(fp);

    fgets(c.contact, sizeof(c.contact), fp);
    c.contact[strcspn(c.contact, "\n")] = '\0';

    fgets(c.address, sizeof(c.address), fp);
    c.address[strcspn(c.address, "\n")] = '\0';

    customers[customercount] = c;
    customercount++;
}

    printf("\n\n===== ALL CUSTOMERS =====\n\n");

    if(customercount == 0)
    {
        printf("No Customers to Show\n");
        return;
    }

    for(int i=0;i<customercount;i++)
    {
        printf("\nID : %d",customers[i].id);
        printf("\nName : %s",customers[i].name);
        printf("\nProduct(s) : %s",customers[i].product);
        printf("\nCategory(s) : %s",customers[i].category);
        printf("\nQuantity(s) : %d",customers[i].customer_qty);
        printf("\nPrice : %.2lf",customers[i].price);
        printf("\nContact : %s",customers[i].contact);
        printf("\nAddress : %s\n\n",customers[i].address);

    }

}

void updatecustomer()
{
    FILE *fp;

    struct customer c;

    int id;

    int found = 0;

    fp = fopen("E:\\AhnafFiles\\customer.txt","r");

    if(fp == NULL)
    {
        printf("\nNo Customer to Show\n");
        return;
    }

    while(1)
    {
    if(fscanf(fp,"%d",&c.id) != 1)
    break;
    clearBuffer(fp);

    fgets(c.name, sizeof(c.name), fp);
    c.name[strcspn(c.name, "\n")] = '\0';

    fgets(c.product, sizeof(c.product), fp);
    c.product[strcspn(c.product, "\n")] = '\0';

    fgets(c.category, sizeof(c.category), fp);
    c.category[strcspn(c.category, "\n")] = '\0';

    fscanf(fp, "%d\n",&c.customer_qty);
    clearBuffer(fp);

    fscanf(fp, "%lf\n",&c.price);
    clearBuffer(fp);

    fgets(c.contact, sizeof(c.contact), fp);
    c.contact[strcspn(c.contact, "\n")] = '\0';

    fgets(c.address, sizeof(c.address), fp);
    c.address[strcspn(c.address, "\n")] = '\0';

    customers[customercount] = c;
    customercount++;
    }

    printf("\nEnter Customer ID to Find and Update : ");
    scanf("%d",&id);
    clearbuffer();

    for(int i=0;i<customercount;i++)
    {
        if(customers[i].id == id)
        {
            printf("\nID : %d",customers[i].id);
            printf("\nName : %s",customers[i].name);
            printf("\nProduct(s) : %s",customers[i].product);
            printf("\nCategory(s) : %s",customers[i].category);
            printf("\nQuantity(s) : %d",customers[i].customer_qty);
            printf("\nPrice : %.2lf",customers[i].price);
            printf("\nContact : %s",customers[i].contact);
            printf("\nAddress : %s\n\n",customers[i].address);

            printf("\n\n===== ENTER NEW DETAILS =====\n\n");

            printf("\nEnter Updated Name : ");
            fgets(customers[i].name, sizeof(customers[i].name), stdin);
            customers[i].name[strcspn(customers[i].name,"\n")]='\0';

            printf("\nEnter Updated Product : ");
            fgets(customers[i].product, sizeof(customers[i].product), stdin);
            customers[i].product[strcspn(customers[i].product,"\n")]='\0';

            printf("\nEnter Updated Product Category : ");
            fgets(customers[i].category, sizeof(customers[i].category), stdin);
            customers[i].category[strcspn(customers[i].category,"\n")]='\0';

            printf("\nEnter Updated Quantity : ");
            scanf("%d",&customers[i].customer_qty);

            printf("\nEnter Updated Price : ");
            scanf("%lf",&customers[i].price);
            clearbuffer();

            printf("\nEnter Updated Contact : ");
            fgets(customers[i].contact, sizeof(customers[i].contact), stdin);
            customers[i].contact[strcspn(customers[i].contact,"\n")]='\0';

            printf("\nEnter Updated Address : ");
            fgets(customers[i].address, sizeof(customers[i].address), stdin);
            customers[i].address[strcspn(customers[i].address,"\n")]='\0';

            printf("\n\n");

            found++;

            break;
        }

    }

    fp = fopen("E:\\AhnafFiles\\customer.txt","w");

    if(fp == NULL)
    {
        printf("Error Writing File\n");
        return;
    }

    for(int i=0;i<customercount;i++)
    {
       fprintf(fp,"%d\n %s\n %s\n %s\n %d\n %lf\n %s\n %s\n",customers[i].id, customers[i].name, customers[i].product, customers[i].category, customers[i].customer_qty, customers[i].price, customers[i].contact, customers[i].address);
    }

    fclose(fp);

    printf("\nCustomer Updated Successfully!\n");

}

void searchcustomer()
{
    FILE *fp;

    char ckey[100];

    int found = 0;

    struct customer c;

    customercount = 0;

    fp = fopen("E:\\AhnafFiles\\customer.txt","r");

    if(fp == NULL)
    {
        printf("\nNo Customer to Show\n");
        return;
    }

   while(1)
   {
    if(fscanf(fp,"%d",&c.id) != 1)
    break;
    clearBuffer(fp);

    fgets(c.name, sizeof(c.name), fp);
    c.name[strcspn(c.name, "\n")] = '\0';

    fgets(c.product, sizeof(c.product), fp);
    c.product[strcspn(c.product, "\n")] = '\0';

    fgets(c.category, sizeof(c.category), fp);
    c.category[strcspn(c.category, "\n")] = '\0';

    fscanf(fp, "%d\n",&c.customer_qty);
    clearBuffer(fp);

    fscanf(fp, "%lf\n",&c.price);
    clearBuffer(fp);

    fgets(c.contact, sizeof(c.contact), fp);
    c.contact[strcspn(c.contact, "\n")] = '\0';

    fgets(c.address, sizeof(c.address), fp);
    c.address[strcspn(c.address, "\n")] = '\0';

    customers[customercount] = c;
    customercount++;
    }

    if(customercount == 0)
    {
        printf("\nNo Customer To Show\n");
        return;
    }

    printf("\nEnter Customer Name To Search : ");
    fgets(ckey, sizeof(ckey), stdin);
    ckey[strcspn(ckey,"\n")]='\0';

    printf("\n====== SEARCH LIST ======\n");

    for(int i=0;i<customercount;i++)
    {
        if(strcasecmp(ckey, customers[i].name) == 0)
        {
            printf("\nID : %d",customers[i].id);
            printf("\nName : %s",customers[i].name);
            printf("\nProduct(s) : %s",customers[i].product);
            printf("\nCategory(s) : %s",customers[i].category);
            printf("\nQuantity(s) : %d",customers[i].customer_qty);
            printf("\nPrice : %.2lf",customers[i].price);
            printf("\nContact : %s",customers[i].contact);
            printf("\nAddress : %s\n\n",customers[i].address);

            found++;
        }

    }

        if(found == 0)
        {
            printf("\nNo Customer Matched\n");
            return;
        }

}

void addsupplier()
{
    struct supplier su;
    FILE *fp;

    printf("\nEnter ID : ");
    scanf("%d",&su.id);
    clearbuffer();

    printf("\nEnter Name : ");
    fgets(su.name, sizeof(su.name), stdin);
    su.name[strcspn(su.name,"\n")]='\0';

    printf("\nEnter contact : ");
    fgets(su.contact, sizeof(su.contact), stdin);
    su.contact[strcspn(su.contact,"\n")]='\0';

    printf("\nEnter Address : ");
    fgets(su.address, sizeof(su.address), stdin);
    su.address[strcspn(su.address,"\n")]='\0';

    printf("\nEnter Supply Type : ");
    fgets(su.supplytype, sizeof(su.supplytype), stdin);
    su.supplytype[strcspn(su.supplytype,"\n")]='\0';

    printf("\nEnter Last Supply Date : ");
    fgets(su.lastsupplydate, sizeof(su.lastsupplydate), stdin);
    su.lastsupplydate[strcspn(su.lastsupplydate,"\n")]='\0';

    printf("\nEnter Supplier Activity : ");
    fgets(su.active, sizeof(su.active), stdin);
    su.active[strcspn(su.active,"\n")]='\0';

    suppliers[suppliercount]=su;
    suppliercount++;

    fp = fopen("E:\\AhnafFiles\\supplier.txt","a");
    if(fp == NULL)
    {
        printf("File not ready for writing\n");
        return;
    }

    fprintf(fp,"%d\n %s\n %s\n %s\n %s\n %s\n %s\n",su.id, su.name, su.contact, su.address, su.supplytype, su.lastsupplydate, su.active);

    fclose(fp);

    printf("\nSupplier Saved with ID %d !\n",su.id);

}

void viewsupplier()
{
    FILE *fp;
    struct supplier su;

    fp = fopen("E:\\AhnafFiles\\supplier.txt","r");

    if(fp == NULL)
    {
        printf("\nNo Suppliers Found!\n");
        return;
    }

    suppliercount = 0;

    while(1)
   {
    if(fscanf(fp,"%d",&su.id) != 1)
    break;
    clearBuffer(fp);

    fgets(su.name, sizeof(su.name), fp);
    su.name[strcspn(su.name, "\n")] = '\0';

    fgets(su.contact, sizeof(su.contact), fp);
    su.contact[strcspn(su.contact, "\n")] = '\0';

    fgets(su.address, sizeof(su.address), fp);
    su.address[strcspn(su.address, "\n")] = '\0';

    fgets(su.supplytype, sizeof(su.supplytype), fp);
    su.supplytype[strcspn(su.supplytype, "\n")] = '\0';

    fgets(su.lastsupplydate, sizeof(su.lastsupplydate), fp);
    su.lastsupplydate[strcspn(su.lastsupplydate, "\n")] = '\0';

    fgets(su.active, sizeof(su.active), fp);
    su.active[strcspn(su.active, "\n")] = '\0';

    suppliers[suppliercount] = su;
    suppliercount++;
}

    printf("\n\n===== ALL SUPPLIERS =====\n\n");

    if(suppliercount == 0)
    {
        printf("No Suppliers to Show\n");
        return;
    }

    for(int i=0;i<suppliercount;i++)
    {
        printf("\nID : %d",suppliers[i].id);
        printf("\nName : %s",suppliers[i].name);
        printf("\nContact : %s",suppliers[i].contact);
        printf("\nAddress : %s",suppliers[i].address);
        printf("\nSupply Type : %s",suppliers[i].supplytype);
        printf("\nLast Supply Date: %s",suppliers[i].lastsupplydate);
        printf("\nActivity : %s\n\n",suppliers[i].active);

    }

}

void updatesupplier()
{
    FILE *fp;

    struct supplier su;

    int found = 0;

    int suid;

    fp = fopen("E:\\AhnafFiles\\supplier.txt","r");

    if(fp == NULL)
    {
        printf("\nNo Supplier to Show\n");
        return;
    }

     suppliercount = 0;

    while(1)
   {
    if(fscanf(fp,"%d",&su.id) != 1)
    break;
    clearBuffer(fp);

    fgets(su.name, sizeof(su.name), fp);
    su.name[strcspn(su.name, "\n")] = '\0';

    fgets(su.contact, sizeof(su.contact), fp);
    su.contact[strcspn(su.contact, "\n")] = '\0';

    fgets(su.address, sizeof(su.address), fp);
    su.address[strcspn(su.address, "\n")] = '\0';

    fgets(su.supplytype, sizeof(su.supplytype), fp);
    su.supplytype[strcspn(su.supplytype, "\n")] = '\0';

    fgets(su.lastsupplydate, sizeof(su.lastsupplydate), fp);
    su.lastsupplydate[strcspn(su.lastsupplydate, "\n")] = '\0';

    fgets(su.active, sizeof(su.active), fp);
    su.active[strcspn(su.active, "\n")] = '\0';

    suppliers[suppliercount] = su;
    suppliercount++;
    }

    fclose(fp);

    printf("\nEnter Supplier ID to Find and Update : ");
    scanf("%d",&suid);
    clearbuffer();

    for(int i=0;i<suppliercount;i++)
    {
        if(suppliers[i].id == suid)
        {
            printf("\nID : %d",suppliers[i].id);
            printf("\nName : %s",suppliers[i].name);
            printf("\nContact : %s",suppliers[i].contact);
            printf("\nAddress : %s",suppliers[i].address);
            printf("\nSupply Type : %s",suppliers[i].supplytype);
            printf("\nLast Supply Date : %s",suppliers[i].lastsupplydate);
            printf("\nSupplier Activity : %s",suppliers[i].active);


            printf("\n\n===== ENTER NEW DETAILS =====\n\n");
            printf("\nEnter Updated Name : ");
            fgets(suppliers[i].name, sizeof(suppliers[i].name), stdin);
            suppliers[i].name[strcspn(suppliers[i].name,"\n")]='\0';

            printf("\nEnter Updated Contact : ");
            fgets(suppliers[i].contact, sizeof(suppliers[i].contact), stdin);
            suppliers[i].contact[strcspn(suppliers[i].contact,"\n")]='\0';

            printf("\nEnter Updated Address : ");
            fgets(suppliers[i].address, sizeof(suppliers[i].address), stdin);
            suppliers[i].address[strcspn(suppliers[i].address,"\n")]='\0';

            printf("\nEnter Updated Supply type : ");
            fgets(suppliers[i].supplytype, sizeof(suppliers[i].supplytype), stdin);
            suppliers[i].supplytype[strcspn(suppliers[i].supplytype, "\n")]='\0';

            printf("\nEnter Updated Last Supply Date : ");
            fgets(suppliers[i].lastsupplydate, sizeof(suppliers[i].lastsupplydate), stdin);
            suppliers[i].lastsupplydate[strcspn(suppliers[i].lastsupplydate,"\n")]='\0';

            printf("\nEnter Updated Supplier Activity : ");
            fgets(suppliers[i].active, sizeof(suppliers[i].active), stdin);
            suppliers[i].active[strcspn(suppliers[i].active,"\n")]='\0';

            printf("\n\n");

            found++;

            break;
        }

    }

    if(found == 0)
    {
        printf("\nSupplier ID not Found\n");
        return;
    }

    fp = fopen("E:\\AhnafFiles\\supplier.txt","w");

    if(fp == NULL)
    {
        printf("Error Writing File\n");
        return;
    }

    for(int i=0;i<suppliercount;i++)
    {
       fprintf(fp,"%d\n %s\n %s\n %s\n %s\n %s\n %s\n",suppliers[i].id, suppliers[i].name, suppliers[i].contact, suppliers[i].address,   suppliers[i].supplytype, suppliers[i].lastsupplydate, suppliers[i].active);
    }

    fclose(fp);

    printf("\nSupplier Updated Successfully!\n");

}

void searchsupplier()
{
    FILE *fp;

    char sukey[100];

    int found = 0;

    struct supplier su;

    fp = fopen("E:\\AhnafFiles\\supplier.txt","r");

    if(fp == NULL)
    {
        printf("\nNo Supplier to Show\n");
        return;
    }

     suppliercount = 0;

    while(1)
   {
    if(fscanf(fp,"%d",&su.id) != 1)
    break;
    clearBuffer(fp);

    fgets(su.name, sizeof(su.name), fp);
    su.name[strcspn(su.name, "\n")] = '\0';

    fgets(su.contact, sizeof(su.contact), fp);
    su.contact[strcspn(su.contact, "\n")] = '\0';

    fgets(su.address, sizeof(su.address), fp);
    su.address[strcspn(su.address, "\n")] = '\0';

    fgets(su.supplytype, sizeof(su.supplytype), fp);
    su.supplytype[strcspn(su.supplytype, "\n")] = '\0';

    fgets(su.lastsupplydate, sizeof(su.lastsupplydate), fp);
    su.lastsupplydate[strcspn(su.lastsupplydate, "\n")] = '\0';

    fgets(su.active, sizeof(su.active), fp);
    su.active[strcspn(su.active, "\n")] = '\0';

    suppliers[suppliercount] = su;
    suppliercount++;
    }


    fclose(fp);

    if(suppliercount == 0)
    {
        printf("\nNo Supplier To Show\n");
    }

    printf("\nEnter Supplier Name To Search : ");
    fgets(sukey, sizeof(sukey), stdin);
    sukey[strcspn(sukey,"\n")]='\0';

    printf("\n========= SEARCH LIST ==========\n");

    for(int i=0;i<suppliercount;i++)
    {
        if(strcmp(sukey, suppliers[i].name) == 0)
        {
            printf("\nID : %d",suppliers[i].id);
            printf("\nName : %s",suppliers[i].name);
            printf("\nContact : %s",suppliers[i].contact);
            printf("\nAddress : %s",suppliers[i].address);
            printf("\nSupply Type : %s",suppliers[i].supplytype);
            printf("\nLast Supply DAte: %s",suppliers[i].lastsupplydate);
            printf("\nSupplier Activity : %s\n\n",suppliers[i].active);

            found++;

            break;

        }

    }

        if(found == 0)
        {
            printf("\nNo Supplier Matched\n");
            return;
        }

}

void addemployee()
{
    struct employee em;

    printf("\nEnter ID : ");
    scanf("%d",&em.id);
    clearbuffer();

    printf("\nEnter Name : ");
    fgets(em.name, sizeof(em.name), stdin);
    em.name[strcspn(em.name, "\n")] = '\0';

    printf("\nEnter Position : ");
    fgets(em.position, sizeof(em.position), stdin);
    em.position[strcspn(em.position, "\n")] = '\0';

    printf("\nEnter Contact : ");
    fgets(em.contact, sizeof(em.contact), stdin);
    em.contact[strcspn(em.contact, "\n")] = '\0';

    printf("\nEnter Address : ");
    fgets(em.address, sizeof(em.address), stdin);
    em.address[strcspn(em.address, "\n")] = '\0';

    printf("\nEnter Activity : ");
    fgets(em.active, sizeof(em.active), stdin);
    em.active[strcspn(em.active, "\n")] = '\0';

    employees[employeecount] = em;
    employeecount++;

    FILE *fp;
    fp = fopen("E:\\AhnafFiles\\employee.txt","a");

    if(fp == NULL)
    {
        printf("\nNothing To Show\n");
        return;
    }

    fprintf(fp,"%d\n %s\n %s\n %s\n %s\n %s\n",em.id, em.name, em.position, em.contact, em.address, em.active);

    fclose(fp);

    printf("\nEmployee Successfully Added With ID %d !\n",em.id);

}

void viewemployee()
{
    FILE *fp;

    struct employee em;

    fp = fopen("E:\\AhnafFiles\\employee.txt","r");

    if(!fp)
    {
        printf("\nError Loading File\n");
        return;
    }

    employeecount = 0;

    while(1)
   {
    if(fscanf(fp,"%d",&em.id) != 1)
    break;
    clearBuffer(fp);

    fgets(em.name, sizeof(em.name), fp);
    em.name[strcspn(em.name, "\n")] = '\0';

    fgets(em.position, sizeof(em.position), fp);
    em.position[strcspn(em.position, "\n")] = '\0';

    fgets(em.contact, sizeof(em.contact), fp);
    em.contact[strcspn(em.contact, "\n")] = '\0';

    fgets(em.address, sizeof(em.address), fp);
    em.address[strcspn(em.address, "\n")] = '\0';

    fgets(em.active, sizeof(em.active), fp);
    em.active[strcspn(em.active, "\n")] = '\0';

    employees[employeecount] = em;
    employeecount++;
}


    printf("\n====== ALL EMPLOYEES ======\n\n");

    if(employeecount == 0)
    {
        printf("\nNo Employee to Show\n\n");
        return;
    }

    for(int i=0;i<employeecount;i++)
    {
        printf("\nID : %d",employees[i].id);
        printf("\nName : %s",employees[i].name);
        printf("\nPosition : %s",employees[i].position);
        printf("\nContact : %s",employees[i].contact);
        printf("\nAddress : %s",employees[i].address);
        printf("\nEmployee Activity : %s\n\n",employees[i].active);

    }

}

void updateemployee()
{
    FILE *fp;

    struct employee em;

    int found = 0;

    int emid;

    fp = fopen("E:\\AhnafFiles\\employee.txt","r");

    if(fp == NULL)
    {
        printf("\nError Loading File\n");
        return;
    }

    employeecount = 0;

    while(1)
   {
    if(fscanf(fp,"%d",&em.id) != 1)
    break;
    clearBuffer(fp);

    fgets(em.name, sizeof(em.name), fp);
    em.name[strcspn(em.name, "\n")] = '\0';

    fgets(em.position, sizeof(em.position), fp);
    em.position[strcspn(em.position, "\n")] = '\0';

    fgets(em.contact, sizeof(em.contact), fp);
    em.contact[strcspn(em.contact, "\n")] = '\0';

    fgets(em.address, sizeof(em.address), fp);
    em.address[strcspn(em.address, "\n")] = '\0';

    fgets(em.active, sizeof(em.active), fp);
    em.active[strcspn(em.active, "\n")] = '\0';

    employees[employeecount] = em;
    employeecount++;

}


    printf("\nEnter Employee ID to Find And Update : ");
    scanf("%d",&emid);
    clearbuffer();

    for(int i=0;i<employeecount;i++)
    {
        if(employees[i].id == emid)
        {
            printf("\n1.ID : %d",employees[i].id);
            printf("\n2.Name : %s",employees[i].name);
            printf("\n3.Position : %s",employees[i].position);
            printf("\n4.Contact : %s",employees[i].contact);
            printf("\n5.Address : %s",employees[i].address);
            printf("\n6. Employee Activity : %s\n",employees[i].active);

            printf("\n\n====== Enter Updated Details ======\n\n");

            printf("Enter Updated Name : ");
            fgets(employees[i].name, sizeof(employees[i].name), stdin);
            employees[i].name[strcspn(employees[i].name, "\n")] = '\0';

            printf("Enter Updated Position : ");
            fgets(employees[i].position, sizeof(employees[i].position), stdin);
            employees[i].position[strcspn(employees[i].position, "\n")] = '\0';

            printf("Enter Updated Contact : ");
            fgets(employees[i].contact, sizeof(employees[i].contact), stdin);
            employees[i].contact[strcspn(employees[i].contact, "\n")] = '\0';

            printf("Enter Updated Address : ");
            fgets(employees[i].address, sizeof(employees[i].address), stdin);
            employees[i].address[strcspn(employees[i].address, "\n")] = '\0';

            printf("Enter Updated Employee Activity : ");
            fgets(employees[i].active, sizeof(employees[i].active), stdin);
            employees[i].active[strcspn(employees[i].active, "\n")] = '\0';

            found++;

            break;

        }

    }

    if(found == 0)
    {
        printf("\nNo Matched Employee ID was Found\n");
        return;
    }

    fp = fopen("E:\\AhnafFiles\\employee.txt","w");

    if(fp == NULL)
    {
        printf("\nError Loading Files\n");
        return;
    }

    for(int i=0;i<employeecount;i++)
    {
        fprintf(fp,"%d\n %s\n %s\n %s\n %s\n %s\n",employees[i].id, employees[i].name, employees[i].position, employees[i].contact, employees[i].address, employees[i].active);
    }

    fclose(fp);

    printf("\nEmployee Updated Successfully!\n");

}

void searchemployee()
{
    FILE *fp;

    char emkey[100];

    int found = 0;

    struct employee em;


    fp = fopen("E:\\AhnafFiles\\employee.txt","r");

    if(fp == NULL)
    {
        printf("\nNo Employee to Show\n");
        return;
    }

     employeecount = 0;

    while(1)
   {
    if(fscanf(fp,"%d",&em.id) != 1)
    break;
    clearBuffer(fp);

    fgets(em.name, sizeof(em.name), fp);
    em.name[strcspn(em.name, "\n")] = '\0';

    fgets(em.position, sizeof(em.position), fp);
    em.position[strcspn(em.position, "\n")] = '\0';

    fgets(em.contact, sizeof(em.contact), fp);
    em.contact[strcspn(em.contact, "\n")] = '\0';

    fgets(em.address, sizeof(em.address), fp);
    em.address[strcspn(em.address, "\n")] = '\0';

    fgets(em.active, sizeof(em.active), fp);
    em.active[strcspn(em.active, "\n")] = '\0';

    employees[employeecount] = em;
    employeecount++;

}


    printf("\nEnter Employee Name to Search : ");
    fgets(emkey, sizeof(emkey), stdin);
    emkey[strcspn(emkey,"\n")]='\0';

    printf("\n\n====== SEARCH LIST ======\n\n");

    for(int i=0;i<employeecount;i++)
    {
        if(strcmp(employees[i].name,emkey) == 0)
        {
            printf("ID : %d\n",employees[i].id);
            printf("Name : %s\n",employees[i].name);
            printf("Position : %s\n",employees[i].position);
            printf("Contact : %s\n",employees[i].contact);
            printf("Address : %s\n",employees[i].address);
            printf("Employee Activity : %s\n",employees[i].active);

            found++;

            break;

        }

    }

    if(found == 0)
    {
        printf("\nNo Employee Matched\n");
        return;
    }

}

void loadProductCount()
{
    FILE *fp;

    fp = fopen("E://AhnafFiles//products.txt", "r");

    struct product p;

    productcount = 0;

    if(!fp)
    {
       return;
    }

    while(fgets(p.name, sizeof(p.name), fp))
    {
        fgets(p.type, sizeof(p.type), fp);

        fscanf(fp, "%d", &p.stock);
        clearBuffer(fp);

        fscanf(fp, "%d", &p.price);
        clearBuffer(fp);

        fscanf(fp, "%d %d %d", &p.added.day, &p.added.month, &p.added.year);
        clearBuffer(fp);

        productcount++;

    }

    fclose(fp);

}

void loadCustomerCount()
{
    FILE *fp;

    struct customer c;

    fp = fopen("E:\\AhnafFiles\\customer.txt", "r");

    customercount = 0;

    if (fp == NULL)
        return;

    while (1)
    {
        if (fscanf(fp, "%d", &c.id) != 1)
            break;
        clearBuffer(fp);

        fgets(c.name, sizeof(c.name), fp);

        fgets(c.product, sizeof(c.product), fp);

        fgets(c.category, sizeof(c.category), fp);

        fscanf(fp, "%d", &c.customer_qty);
        clearBuffer(fp);

        fscanf(fp, "%lf", &c.price);
        clearBuffer(fp);

        fgets(c.contact, sizeof(c.contact), fp);
        fgets(c.address, sizeof(c.address), fp);

        customercount++;

    }

    fclose(fp);

}

void loadSupplierCount()
{
    FILE *fp;

    struct supplier s;

    fp = fopen("E:\\AhnafFiles\\supplier.txt", "r");

    suppliercount = 0;

    if (fp == NULL)
    {
        return;
    }

    while (1)
    {
        if (fscanf(fp, "%d", &s.id) != 1)
            break;
        clearBuffer(fp);

        fgets(s.name, sizeof(s.name), fp);

        fgets(s.contact, sizeof(s.contact), fp);

        fgets(s.address, sizeof(s.address), fp);

        fgets(s.supplytype, sizeof(s.supplytype), fp);

        fgets(s.lastsupplydate, sizeof(s.lastsupplydate), fp);

        fgets(s.active, sizeof(s.active), fp);


        suppliercount++;

    }

    fclose(fp);

}

void loadEmployeeCount()
{
    FILE *fp;

    struct employee em;

    fp = fopen("E:\\AhnafFiles\\employee.txt", "r");

    employeecount = 0;

    if (fp == NULL)
    {
        return;
    }

    while (1)
    {
        if (fscanf(fp, "%d", &em.id) != 1)
            break;
        clearBuffer(fp);

        fgets(em.name, sizeof(em.name), fp);
        em.name[strcspn(em.name, "\n")] = '\0';

        fgets(em.position, sizeof(em.position), fp);
        em.position[strcspn(em.position, "\n")] = '\0';

        fgets(em.contact, sizeof(em.contact), fp);
        em.contact[strcspn(em.contact, "\n")] = '\0';

        fgets(em.address, sizeof(em.address), fp);
        em.address[strcspn(em.address, "\n")] = '\0';

        fgets(em.active, sizeof(em.active), fp);
        em.active[strcspn(em.active, "\n")] = '\0';

        employeecount++;

    }

    fclose(fp);

}


void dashboard()
{

    int dash;

    loadProductCount();

    loadCustomerCount();

    loadSupplierCount();

    loadEmployeeCount();

    do
    {
        printf("\n========== DASHBOARD ==========\n\n");

        printf("1. Total Products : %d\n",productcount);
        printf("2. Total Sales : %d\n",flag);
        printf("3. Total Customers : %d\n",customercount);
        printf("4. Total Suppliers : %d\n",suppliercount);
        printf("5. total Employee : %d\n",employeecount);

        printf("\n======================================\n\n");

        printf("\nDo You want to Exit? Enter '0' to Exit\n");
        scanf("%d",&dash);
        clearbuffer();

    } while (dash != 0);

}

void productmenu()
{
    int prokey;

    do
    {
        printf("\n====== PRODUCTS MENU ======\n\n");
        printf("1. Add A Product\n");
        printf("2. View All Products\n");
        printf("3. Sorting Menu\n");
        printf("4. Update Product Info\n");
        printf("5. Search Product\n");
        printf("6. Delete Product\n");
        printf("7. Sell Product\n");
        printf("8. Product Report\n");
        printf("0. Exit\n");
        printf("What do you want to choose?\n");
        scanf("%d",&prokey);
        clearbuffer();

    switch(prokey)
    {
        case 1 : addProduct();
        break;

        case 2 : viewProducts();
        break;

        case 3 :sortMenu();
        break;

        case 4 : updateProduct();
        break;

        case 5 : searchProduct();
        break;

        case 6 : deleteProduct();
        break;

        case 7 : sellProduct();
        break;

        case 8 : productReport();
        break;

        case 0 :
        printf("Exiting.....\n");
        break;

        default : printf("Invalid Input. Please try again!\n\n");
    }

    }while(prokey != 0);

}

void customermenu()
{
    int cchoice;

    do
    {
        printf("\n====== CUSTOMER MENU ======\n");
        printf("1. Add Customer\n");
        printf("2. View All Customers\n");
        printf("3. Update Customer Info\n");
        printf("4. Search Customer\n");
        printf("0. Exit\n");

        printf("\nWhat Do You want to Choose?\n");
        scanf("%d",&cchoice);
        clearbuffer();

        switch(cchoice)
        {
            case 1 : addcustomer();
            break;

            case 2 : viewcustomer();
            break;

            case 3 : updatecustomer();
            break;

            case 4 : searchcustomer();
            break;

            case 0 : printf("Exiting....\n\n");
            break;

            default : printf("Not a Valid Input. Please Try Again\n");
        }

    } while (cchoice != 0);

}

void suppliermenu()
{
    int suchoice;

    do
    {
        printf("\n====== SUPPLIER MENU ======\n");
        printf("1. Add Suppliers\n");
        printf("2. View All Suppliers\n");
        printf("3. Update Supplier Info\n");
        printf("4. Search Suppler\n");
        printf("0. Exit\n");

        printf("\nWhat Do You want to Choose?\n");
        scanf("%d",&suchoice);
        clearbuffer();

        switch(suchoice)
        {
            case 1 : addsupplier();
            break;

            case 2 : viewsupplier();
            break;

            case 3 : updatesupplier();
            break;

            case 4 : searchsupplier();
            break;

            case 0 : printf("Exiting....\n\n");
            break;

            default : printf("Not a Valid Input. Please Try Again\n");
        }

    } while (suchoice != 0);

}

void employeemenu()
{
    int emchoice;

    do
    {
        printf("\n====== EMPLOYEE MENU =======\n\n");
        printf("\n1. Add Employee");
        printf("\n2. View All Employees");
        printf("\n3. Update Employee Info");
        printf("\n4. Search Employee");
        printf("\n0. Exit");

        printf("\nWhat do you want to choose?\n");
        scanf("%d",&emchoice);
        clearbuffer();

        switch(emchoice)
        {
            case 1 : addemployee();
            break;

            case 2 : viewemployee();
            break;

            case 3 : updateemployee();
            break;

            case 4 : searchemployee();
            break;

            case 0 :
            printf("\nExiting....\n");
            break;

            default : printf("Invalid Input! Please Try Again!\n");
        }

    }while(emchoice != 0);
}

int main()
{
    int choice;
    do
    {
        printf("\n\n======== ELECTRONIC STORE MANAGEMENT SYSTEM ========\n\n");
        printf("1. Products\n");
        printf("2. Customers\n");
        printf("3. Suppliers\n");
        printf("4. Employees\n");
        printf("5. Dashboard\n");
        printf("0. Exit\n\n");

        printf("What do you want to do?\n");
        scanf("%d",&choice);
        clearbuffer();

    switch(choice)
    {
        case 1 : productmenu();
        break;

        case 2 : customermenu();
        break;

        case 3 : suppliermenu();
        break;

        case 4 : employeemenu();
        break;

        case 5 : dashboard();
        break;

        case 0 :
        printf("\nExiting...\n\n");
        break;

        default : printf("Invalid Input. Please Try Again...\n\n");

    }

    }while(choice != 0);

    return 0;

}



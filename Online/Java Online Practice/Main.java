import java.util.*;

public class Main {
    public static void showCommands() {
        System.out.println("---");
        System.out.println("Commands");
        System.out.println("- search <name>: Search for a product by name and display its details.");
        System.out.println("- sell <name> <quantity>: Sell a product by name, updating its sold quantity and available stock.");
        System.out.println("---");
    }

    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Input count of products in the command line argument.");
            return;
        }
        int howManyProducts = Integer.parseInt(args[0]);

        Inventory inventory = new Inventory(howManyProducts);
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < howManyProducts; i++) {
            Product p = new Product();
            System.out.printf("Enter details for product %d:\n", i + 1);

            System.out.print("Name: ");
            p.setName(scanner.nextLine());

            System.out.print("Category: ");
            p.setCategory(scanner.nextLine());

            System.out.print("Price: ");
            double price = scanner.nextDouble();
            while (!p.verifyPrice(price)) {
                System.out.println("Error: Provide a valid price");
                System.out.print("Price: ");
                price = scanner.nextDouble();
            }
            p.setPrice(price);
            scanner.nextLine();

            System.out.print("Total Quantity: ");
            p.setTotalQuantity(scanner.nextInt());
            scanner.nextLine();

            System.out.print("Sold Quantity: ");
            int soldQuantity = scanner.nextInt();
            while (!p.verifyQuantity(soldQuantity)) {
                System.out.println("Error: Provide a valid quantity");
                System.out.print("Sold Quantity: ");
                soldQuantity = scanner.nextInt();
            }
            p.setSoldQuantity(soldQuantity);
            scanner.nextLine();

            inventory.addProduct(p);
        }
        showCommands();
        Boolean runningCommands = true;
        while (runningCommands) {
            System.out.print("Enter command: ");
            String command = scanner.nextLine();
            String[] partCommands = command.split(" ", 2);
            String action = partCommands[0];

            switch (action) {
                case "exit": {
                    runningCommands = false;
                    break;
                }
                case "search": {
                    String name = partCommands[1];
                    inventory.searchProduct(name);
                }
                case "sell" : {
                    String name = partCommands[1];
                    int quantity = Integer.parseInt(partCommands[2]);
                    inventory.sellProduct(name, quantity);
                }
                default:
                    System.out.println("Not a valid command.");
            }
        }
        scanner.close();
    }
}
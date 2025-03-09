import java.util.*;

public class Main {
    public static void showCommands() {
        System.out.println("---");
        System.out.println("Commands:");
        System.out.println("- search <title>: Search for a movie by title and display details.");
        System.out.println("- rent <title>: Attempt to rent a movie by title, increasing rented copies if available.");
        System.out.println("- terminate: type in \"terminate\".");
        System.out.println("---");
    }

    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Provide the number of movies as command-line argument.");
            return;
        }
        int howManyMovies = Integer.parseInt(args[0]);
        MovieCollection movieCollection = new MovieCollection(howManyMovies);
        Scanner scanner = new Scanner(System.in);
        int i = 0;
        while (i < howManyMovies) {
            Movie m = new Movie();
            System.out.printf("Enter details for movie %d:\n", i + 1);

            System.out.print("Title: ");
            m.setTitle(scanner.nextLine());

            System.out.print("Genre: ");
            m.setGenre(scanner.nextLine());

            System.out.print("Rating(out of 10): ");
            double rating = scanner.nextDouble();
            while (!m.verifyRating(rating)) {
                System.out.println("Please input again with proper rating.");
                System.out.print("Rating(out of 10): ");
                rating = scanner.nextDouble();
            }
            m.setRating(rating);
            scanner.nextLine();

            System.out.print("Total Copies: ");
            m.setTotalCopies(scanner.nextInt());
            scanner.nextLine();

            System.out.print("Rented Copies: ");
            m.setRentedCopies(scanner.nextInt());
            scanner.nextLine();

            movieCollection.addMovie(m);

            i++;
        }
        showCommands();
        Boolean runningCommands = true;
        while (runningCommands) {
            System.out.print("Enter command: ");
            String command = scanner.nextLine();
            String[] commandParts = command.split(" ", 2);
            String action = commandParts[0];
            String title = commandParts.length > 1 ? commandParts[1] : "";
            switch (action) {
                case "terminate": {
                    runningCommands = false;
                    break;
                }
                case "search": {
                    movieCollection.searchMovie(title);
                    break;
                }
                case "rent": {
                    movieCollection.rentMovie(title);
                    break;
                }
                default: {
                    System.out.println("Not a valid command.");
                }
            }
        }
        scanner.close();
    }
}

import javafx.scene.control.*;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;

public class q4 extends Application {
    public void start(Stage primaryStage) {

        Label num1 = new Label("num1:");
        Label num2 = new Label("num2:");
        Label ans = new Label();
        ans.setWrapText(true);
        ans.setMaxWidth(200);
        TextField num1tf = new TextField();
        TextField num2tf = new TextField();
        Button submit = new Button("find gcd");

        submit.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent e) {
                String n1Str = num1tf.getText();
                String n2Str = num2tf.getText();
                String s = "numbers are " + n1Str + " and " + n2Str + "\ngcd = ";
                int n1 = Integer.parseInt(n1Str);
                int n2 = Integer.parseInt(n2Str);
                if (n2 < n1) {
                    int temp = n1;
                    n1 = n2;
                    n2 = temp;
                }
                int gcd = 1;
                for (int i = 1; i <= n1; i++)
                    if ((n1 % i == 0) && (n2 % i == 0))
                        gcd = i;
                s = s + Integer.toString(gcd);
                ans.setText(s);
            }
        });
        GridPane grid = new GridPane();
        grid.setPadding(new Insets(10, 10, 10, 10));
        grid.setVgap(5);
        grid.setHgap(5);
        GridPane.setConstraints(num1, 0, 0);
        GridPane.setConstraints(num1tf, 1, 0);
        GridPane.setConstraints(num2, 0, 1);
        GridPane.setConstraints(num2tf, 1, 1);
        GridPane.setConstraints(ans, 1, 2);
        GridPane.setConstraints(submit, 0, 2);
        grid.getChildren().addAll(num1, num1tf, num2, num2tf, ans, submit);
        grid.setAlignment(Pos.CENTER);
        Scene scene = new Scene(grid, 500, 500);
        primaryStage.setScene(scene);
        primaryStage.setTitle("gcd calci");
        primaryStage.show();
    }

    public static void main(String args[]) {
        launch(args);
    }
}
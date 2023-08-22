import javafx.scene.control.*;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;

public class q3 extends Application {
    public void start(Stage primaryStage) {

        Label welcome = new Label("Welcome");
        Label user = new Label("User Name:");
        Label pass = new Label("Password:");
        Label success = new Label();
        TextField usertf = new TextField();
        PasswordField passtf = new PasswordField();
        Button submit = new Button("Sign in");

        submit.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent e) {
                String s = "Welcome ";
                s = s + usertf.getText();
                success.setText(s);
            }
        });
        GridPane grid = new GridPane();
        grid.setPadding(new Insets(10, 10, 10, 10));
        grid.setVgap(5);
        grid.setHgap(5);
        GridPane.setConstraints(welcome, 0, 0);
        GridPane.setConstraints(user, 0, 1);
        GridPane.setConstraints(usertf, 1, 1);
        GridPane.setConstraints(pass, 0, 2);
        GridPane.setConstraints(passtf, 1, 2);
        GridPane.setConstraints(success, 1, 3);
        GridPane.setConstraints(submit, 2, 3);
        grid.getChildren().addAll(welcome, user, usertf, pass, passtf, success,
                submit);
        grid.setAlignment(Pos.CENTER);
        Scene scene = new Scene(grid, 500, 500);
        primaryStage.setScene(scene);
        primaryStage.setTitle("JavaFX Welcome");
        primaryStage.show();
    }

    public static void main(String args[]) {
        launch(args);
    }
}
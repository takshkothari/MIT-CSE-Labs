
import javafx.scene.control.*;
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;

public class q1 extends Application {
    public void start(Stage primaryStage) {
        Label label = new Label("welcome to javafx programming");
        label.setTextFill(Color.MAGENTA);
        FlowPane root = new FlowPane(6, 9);
        root.getChildren().add(label);
        root.setAlignment(Pos.CENTER);
        Scene scene = new Scene(root, 500, 200);
        primaryStage.setScene(scene);
        primaryStage.setTitle("this is the first javafx application");
        primaryStage.show();
    }

    public static void main(String args[]) {
        launch(args);
    }
}
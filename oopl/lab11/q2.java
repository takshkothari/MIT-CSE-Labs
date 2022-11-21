import javafx.scene.control.*;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;

public class q2 extends Application {
    public void start(Stage primaryStage) {
        Label multTable = new Label();
        multTable.setAlignment(Pos.CENTER);
        TextField txtField = new TextField();
        Label label = new Label("enter a number");
        Button submit = new Button("show table");

        submit.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent ae) {

                int n = Integer.parseInt(txtField.getText());
                String s = "\ntable of " + n + ": ";
                for (int i = 1; i <= 10; i++)
                    s = s + (i * n) + " ";
                multTable.setText(s);
            }
        });

        HBox hb = new HBox(label, txtField, submit);
        VBox vb = new VBox(hb, multTable);
        hb.setSpacing(15);
        FlowPane root = new FlowPane(6, 9);
        root.getChildren().add(vb);
        root.setAlignment(Pos.CENTER);
        Scene scene = new Scene(root, 690, 420);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Tables");
        primaryStage.show();
    }

    public static void main(String args[]) {
        launch(args);
    }
}
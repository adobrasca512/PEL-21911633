package controlador;

import java.io.IOException;

import com.jfoenix.controls.JFXTextField;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.stage.Modality;
import javafx.stage.Stage;

public class ControladorVentana1 {

	@FXML
	private JFXTextField texto1;

	@FXML
	private JFXTextField texto2;

	@FXML
	private Button botonEncadenar;

	@FXML
	void encadenar(ActionEvent event) {
		try {

			FXMLLoader loader = new FXMLLoader(getClass().getResource("/vista/FRASE_ENCADENADA.fxml"));

			Parent root = loader.load();
			ControladorVentana2 reset = loader.getController();
			reset.setLabel(texto1.getText() + " " + texto2.getText());

			Scene scene = new Scene(root);
			Stage stage = new Stage();
			stage.initModality(Modality.APPLICATION_MODAL);
			stage.setScene(scene);

			stage.showAndWait();

		} catch (IOException e) {
			e.printStackTrace();
		}

	}

}

package aplication;

import java.net.URL;

import controlador.ControladorVentana1;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class MostrarVentanas {
	public static Stage primaryStage;
	public static String resourcePath;

	private static Object mostrarVentana(String fxmlFile, Object controlador) {
		try {
			primaryStage.close();
			URL url = new URL(resourcePath + "vista/" + fxmlFile);
			FXMLLoader loader = new FXMLLoader(url);

			loader.setController(controlador);
			Parent root = loader.load();

			primaryStage.setScene(new Scene(root));
			primaryStage.show();
		} catch (Exception e) {
			e.printStackTrace();
		}
		return controlador;
	}

	public static Object mostrarIncio() {
		return mostrarVentana("ENCADENA_FRASES.fxml", new ControladorVentana1());
	}
}

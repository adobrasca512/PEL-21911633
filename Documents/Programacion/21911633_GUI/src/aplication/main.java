package aplication;

import javafx.application.Application;

import javafx.stage.Stage;

public class main extends Application {

	@Override
	public void start(Stage primaryStage) {
		try {
		
			primaryStage.setMinWidth(800);
			primaryStage.setMinHeight(600);
			MostrarVentanas.primaryStage = primaryStage;
			MostrarVentanas.resourcePath = this.getClass().getProtectionDomain().getCodeSource().getLocation()
					.toString();
			MostrarVentanas.mostrarIncio();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
  		
		launch(args);
		
	}

}

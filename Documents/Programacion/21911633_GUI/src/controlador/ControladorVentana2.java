package controlador;

import javafx.fxml.FXML;
import javafx.scene.text.Text;

public class ControladorVentana2 {

    @FXML
    private Text label;

	public Text getLabel() {
		return label;
	}

	public void setLabel(String label) {
		this.label.setText(label);
	}

}

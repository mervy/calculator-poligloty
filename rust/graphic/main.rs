use eframe::egui;

fn main() -> Result<(), eframe::Error> {
    let opcoes = eframe::NativeOptions {
        viewport: egui::ViewportBuilder::default()
            .with_inner_size([300.0, 250.0]),
        ..Default::default()
    };

    eframe::run_native(
        "Calculadora em Rust",
        opcoes,
        Box::new(|_cc| Ok(Box::new(CalculadoraApp::default()))),
    )
}

struct CalculadoraApp {
    num1: String,
    num2: String,
    resultado: String,
}

impl Default for CalculadoraApp {
    fn default() -> Self {
        Self {
            num1: String::new(),
            num2: String::new(),
            resultado: String::from("Resultado: "),
        }
    }
}

impl CalculadoraApp {
    fn calcular(&mut self, operacao: char) {
        let n1: f64 = match self.num1.trim().parse() {
            Ok(n) => n,
            Err(_) => { self.resultado = "Erro: Número 1 inválido!".to_string(); return; }
        };

        let n2: f64 = match self.num2.trim().parse() {
            Ok(n) => n,
            Err(_) => { self.resultado = "Erro: Número 2 inválido!".to_string(); return; }
        };

        match operacao {
            '+' => self.resultado = format!("Resultado: {:.2}", n1 + n2),
            '-' => self.resultado = format!("Resultado: {:.2}", n1 - n2),
            '*' => self.resultado = format!("Resultado: {:.2}", n1 * n2),
            '/' => {
                if n2 == 0.0 {
                    self.resultado = "Erro: Divisão por zero!".to_string();
                } else {
                    self.resultado = format!("Resultado: {:.2}", n1 / n2);
                }
            }
            _ => {}
        }
    }
}

impl eframe::App for CalculadoraApp {
    fn update(&mut self, ctx: &egui::Context, _frame: &mut eframe::Frame) {
        egui::CentralPanel::default().show(ctx, |ui| {
            ui.heading("=== Calculadora Visual ===");
            ui.add_space(10.0);

            ui.horizontal(|ui| {
                ui.label("Número 1:");
                ui.text_edit_singleline(&mut self.num1);
            });
            ui.add_space(5.0);

            ui.horizontal(|ui| {
                ui.label("Número 2:");
                ui.text_edit_singleline(&mut self.num2);
            });
            ui.add_space(15.0);

            ui.horizontal(|ui| {
                if ui.button("  +  ").clicked() { self.calcular('+'); }
                if ui.button("  -  ").clicked() { self.calcular('-'); }
                if ui.button("  *  ").clicked() { self.calcular('*'); }
                if ui.button("  /  ").clicked() { self.calcular('/'); }
            });
            ui.add_space(15.0);

            ui.label(&self.resultado);
        });
    }
}

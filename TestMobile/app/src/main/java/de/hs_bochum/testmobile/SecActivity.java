package de.hs_bochum.testmobile;

import android.content.Intent;
import android.graphics.Color;
import android.graphics.PorterDuff;
import android.media.Image;
import android.speech.RecognizerIntent;
import android.speech.SpeechRecognizer;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.ToggleButton;

import java.util.ArrayList;

public class SecActivity extends AppCompatActivity {

    ListView list;
    ProgressBar pb;
    TextView tv, tv2;
    ToggleButton btn, mbtn;
    Button switchbtn;
    ImageView check, no_check, ring, top, down, left, right;

    //RelativeLayout layout;
    //private SpeechRecognizer sepech = null;
    //private Intent recognizerIntent;
    //private String LOG_TAG = "VoiceRecognitionActivity";

    public static final int VOICE_RECOGNITION_REQUEST_CODE = 1234;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main_light);

        list = (ListView) findViewById(R.id.list);
        pb = (ProgressBar) findViewById(R.id.progressBar);
        tv = (TextView) findViewById(R.id.activity_main_light);
        tv2 = (TextView) findViewById(R.id.textView);
        btn = (ToggleButton) findViewById(R.id.toggleButton);
        switchbtn = (Button) findViewById(R.id.switchmode);
        //mbtn = (ToggleButton) findViewById(R.id.switchmode);
        top = (ImageView) findViewById(R.id.topArrow);
        down = (ImageView) findViewById(R.id.downArrow);
        left = (ImageView) findViewById(R.id.leftArrow);
        right = (ImageView) findViewById(R.id.rightArrow);
        ring = (ImageView) findViewById(R.id.ring);
        check = (ImageView) findViewById(R.id.check);
        no_check = (ImageView) findViewById(R.id.no_check);

        /**
         * Day/Night-Modus wechseln

         mbtn.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
        @Override
        public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
        if (isChecked){
        startActivity(nextScreen);
        }else
        System.out.println();
        }
        });*/

        // ClickListener implementieren für den Button zum Wechsel der Activity
        switchbtn.setOnClickListener(new View.OnClickListener() {

            public void onClick(View arg0) {
                //Beenden SecondScreen Activity
                finish();
            }
        });


        /**
         * ToggleButton Funktion
         */
        btn.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (isChecked){
                    showProgressBar();
                    startVoiceRecognitionActivity();
                } else
                    hideProgressBar();
            }
        });

    }

/*
    public void daymode() {
        setContentView(R.layout.activity_main_light);
        tv = (TextView) findViewById(R.id.activity_main_light);
    }

    public void nightmode() {
        setContentView(R.layout.activity_main);
        tv = (TextView) findViewById(R.id.activity_main);
    }
*/
    /**
     * Progressbar Methoden
     */
    //  Progress einblenden
    public void showProgressBar() {
        pb.setVisibility(View.VISIBLE);
        pb.setIndeterminate(true);
        tv2.setVisibility(View.INVISIBLE);  //Untertitel

        //Geht auch in XML, aber erst ab API Level 23.
        int color = Color.GREEN; //Gruen 0xFF00FF00
        pb.getIndeterminateDrawable().setColorFilter(color, PorterDuff.Mode.SRC_IN);
        //pb.getProgressDrawable().setColorFilter(color, PorterDuff.Mode.SRC_IN);
    }

    // Progress ausblenden
    public void hideProgressBar() {
        pb.setVisibility(View.INVISIBLE);
        pb.setIndeterminate(false);
        tv2.setVisibility(View.VISIBLE);

        top.setVisibility(View.INVISIBLE);
        down.setVisibility(View.INVISIBLE);
        left.setVisibility(View.INVISIBLE);
        right.setVisibility(View.INVISIBLE);
    }


    /**
     * Methode für Spracherkennung
     */
    public void startVoiceRecognitionActivity() {

        Intent intent = new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);
        intent.putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL,
                RecognizerIntent.LANGUAGE_MODEL_FREE_FORM); //Sprache einstellen: =>Keine spezielle

        try {
            startActivityForResult(intent, VOICE_RECOGNITION_REQUEST_CODE);

        } catch (Exception e) {
            Toast toast = Toast.makeText(this, "Fehler bei der Initialisierung.\n" +
                    "Internetverbindung erfolderlich.", Toast.LENGTH_LONG);
            toast.setGravity(Gravity.TOP | Gravity.CENTER_HORIZONTAL, 0, 300); //Toast positionieren
            toast.show();
        }
    }


    /**
     * Methode für Ausgabe der Kommandos
     */
    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {

        if (requestCode == VOICE_RECOGNITION_REQUEST_CODE && resultCode == RESULT_OK) {
            ArrayList<String> matches = data.getStringArrayListExtra(RecognizerIntent.EXTRA_RESULTS);
            list.setAdapter(new ArrayAdapter(this, android.R.layout.simple_list_item_1, matches));

            if (matches.contains("Start")||matches.contains("Starte")){
                tv.setText("STARTEN");
                hideProgressBar();

                top.setVisibility(View.VISIBLE);
                down.setVisibility(View.INVISIBLE);
                left.setVisibility(View.INVISIBLE);
                right.setVisibility(View.INVISIBLE);
                check.setVisibility(View.VISIBLE);
                no_check.setVisibility(View.INVISIBLE);

            }

            if (matches.contains("Links")||matches.contains("Left")){
                tv.setText("LINKS");
                hideProgressBar();

                top.setVisibility(View.INVISIBLE);
                down.setVisibility(View.INVISIBLE);
                left.setVisibility(View.VISIBLE);
                right.setVisibility(View.INVISIBLE);
                check.setVisibility(View.INVISIBLE);
                no_check.setVisibility(View.VISIBLE);
            }

            if (matches.contains("Rechts")||matches.contains("Right")){
                tv.setText("RECHTS");
                hideProgressBar();

                top.setVisibility(View.INVISIBLE);
                down.setVisibility(View.INVISIBLE);
                left.setVisibility(View.INVISIBLE);
                right.setVisibility(View.VISIBLE);
                check.setVisibility(View.INVISIBLE);
                no_check.setVisibility(View.VISIBLE);
            }

            if (matches.contains("Stop")||matches.contains("Stopp")){
                tv.setText("LANDEN");
                hideProgressBar();

                top.setVisibility(View.INVISIBLE);
                down.setVisibility(View.VISIBLE);
                left.setVisibility(View.INVISIBLE);
                right.setVisibility(View.INVISIBLE);
                check.setVisibility(View.VISIBLE);
                no_check.setVisibility(View.INVISIBLE);
            }
        }

    }
}

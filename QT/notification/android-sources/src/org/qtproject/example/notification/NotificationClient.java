/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtAndroidExtras module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

package org.qtproject.example.notification;

import android.app.Notification;
import android.app.NotificationManager;
import android.content.Context;

import org.qtproject.qt5.android.bindings.QtActivity;
import org.qtproject.qt5.android.bindings.QtApplication;
import android.util.Log;
import android.content.Context;
import android.os.Bundle;
import android.speech.tts.TextToSpeech;
import java.util.Locale;
import java.lang.String;

//Eigene Imports
import android.content.Intent;
import android.graphics.Color;
import android.graphics.PorterDuff;
import android.media.Image;
import android.speech.RecognizerIntent;
import android.speech.SpeechRecognizer;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.ToggleButton;
import android.widget.ViewSwitcher;
import java.util.ArrayList;

public class NotificationClient extends QtActivity implements TextToSpeech.OnInitListener {
    private static NotificationManager m_notificationManager;
    private static Notification.Builder m_builder;
    private static NotificationClient m_instance;

    private static TextToSpeech tts;

    public NotificationClient()
    {
        m_instance = this;

    }

    public static final int VOICE_RECOGNITION_REQUEST_CODE = 1234;

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
            super.onCreate(savedInstanceState);
            tts = new TextToSpeech(this,this);
    }

    public void onInit(int status) {
            Locale loc = new Locale("de", "","");
            if(tts.isLanguageAvailable(loc) >= TextToSpeech.LANG_AVAILABLE){
                    tts.setLanguage(loc);
            }
           tts.speak("Das Programm wurde gestartet", TextToSpeech.QUEUE_FLUSH, null);

    }

    @Override
      protected void onDestroy() {
              super.onDestroy();
              tts.shutdown();
      }


    /** Methode für Spracherkennung */
    public void startVoiceRecognitionActivity() {

        Intent intent = new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);
        intent.putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL,
                RecognizerIntent.LANGUAGE_MODEL_FREE_FORM); //Sprache einstellen: =>Keine spezielle

        try {
            startActivityForResult(intent, VOICE_RECOGNITION_REQUEST_CODE);

        } catch (Exception e) {
            tts.speak("Internetverbindung erfolderlich", TextToSpeech.QUEUE_FLUSH, null);
            //Toast toast = Toast.makeText(this, "Fehler bei der Initialisierung.\n" +
                  //  "Internetverbindung erfolderlich.", Toast.LENGTH_LONG);
            //toast.setGravity(Gravity.TOP | Gravity.CENTER_HORIZONTAL, 0, 300); //Toast positionieren
            //toast.show();
        }
    }


    /** Methode für Ausgabe der Kommandos
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

*/

     public static void notify(String s) {

             if (s.contains("Starten")){
                tts.speak("Drone startet", TextToSpeech.QUEUE_FLUSH, null);
             }

             if (s.contains("Landen")){
                tts.speak("Drone landet", TextToSpeech.QUEUE_FLUSH, null);
             }

             if (s.contains("Links")){
                tts.speak("Drone fliegt nach links", TextToSpeech.QUEUE_FLUSH, null);
             }

             if (s.contains("Rechts")){
                tts.speak("Drone fliegt nach rechts", TextToSpeech.QUEUE_FLUSH, null);
             }


            //startVoiceRecognitionActivity();

            if (m_notificationManager == null) {
                m_notificationManager = (NotificationManager)m_instance.getSystemService(Context.NOTIFICATION_SERVICE);
                m_builder = new Notification.Builder(m_instance);
                m_builder.setSmallIcon(R.drawable.icon);
                m_builder.setContentTitle("A message from Qt!");
            }

            m_builder.setContentText(s);
            m_notificationManager.notify(1, m_builder.build());
        }
}

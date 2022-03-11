using System.Collections;
using System.Collections.Generic;
using TarodevController;
using UnityEngine;

public class ExtendedAnimator : MonoBehaviour {

    [SerializeField] private ParticleSystem _doubleJumpParticles;
    [SerializeField] private AudioSource _source;
    [SerializeField] private AudioClip _doubleJumpClip,_dashClip;
    [SerializeField] private ParticleSystem _dashParticles,_dashRingParticles;
    [SerializeField] private Transform _dashRingTransform;
    private IExtendedPlayerController _player;

    private bool _dashing;
    
    void Awake() => _player = GetComponentInParent<IExtendedPlayerController>();

    void Update() {
        if (_player.DoubleJumpingThisFrame) {
            _source.PlayOneShot(_doubleJumpClip);
            _doubleJumpParticles.Play();
        }

        if (!_dashing && _player.Dashing) {
            _dashing = true;
            _dashParticles.Play();
            _dashRingTransform.up = new Vector3(_player.Input.X, _player.Input.Y);
            _dashRingParticles.Play();
            _source.PlayOneShot(_dashClip);
        }else if (_dashing && !_player.Dashing) {
            _dashing = false;
            _dashParticles.Stop();
        }
    }
}
